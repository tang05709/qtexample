#include "filecntdlg.h"
#include "ui_filecntdlg.h"

FileCntDlg::FileCntDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileCntDlg)
{
    ui->setupUi(this);

    myCntSocket = new QTcpSocket(this);
    mySrvPort = 5555;
    connect(myCntSocket, SIGNAL(readyRead()), this, SLOT(readChatMsg()));
    myFileNameSize = 0;
    myTotalBytes = 0;
    myRcvedBytes = 0;
}

FileCntDlg::~FileCntDlg()
{
    delete ui;
}

void FileCntDlg::createConnToSrv()
{
    myBlockSize = 0;
    myCntSocket->abort();
    myCntSocket->connectToHost(mySrvAddr, mySrvPort);
    myTime.start();
}

void FileCntDlg::readChatMsg()
{
    QDataStream in(myCntSocket);
    in.setVersion(QDataStream::Qt_5_14);
    float usedTime = myTime.elapsed();
    if (myRcvedBytes <= sizeof(qint64) * 2) {
        if ((myCntSocket->bytesAvailable() >= sizeof(qint64) * 2) && (myFileNameSize == 0)) {
            in >> myTotalBytes >> myFileNameSize;
            myRcvedBytes += sizeof(qint64)*2;
        }
        if ((myCntSocket->bytesAvailable() >= myFileNameSize) && (myFileNameSize != 0)) {
            in >> myFileName;
            myRcvedBytes += myFileNameSize;
            myLocPathFile->open(QFile::WriteOnly);
            ui->leRecv->setText(myFileName);
        } else {
            return;
        }
    }
    if (myRcvedBytes < myTotalBytes) {
        myRcvedBytes += myCntSocket->bytesAvailable();
        myInputputBlock = myCntSocket->readAll();
        myLocPathFile->write(myInputputBlock);
        myInputputBlock.resize(0);
    }
    ui->progressRecv->setMaximum(myTotalBytes);
    ui->progressRecv->setValue(myRcvedBytes);
    double transpeed = myRcvedBytes / usedTime;
    ui->leRecvSize->setText(tr("%1").arg(myTotalBytes / (1024 * 1024)) + "MB");
    ui->leRecvCurrentSize->setText(tr("%1").arg(myRcvedBytes / (1024 * 1024)) + "MB");
    if (myRcvedBytes == myTotalBytes) {
        myLocPathFile->close();
        myCntSocket->close();

    }
}


void FileCntDlg::closeEvent(QCloseEvent *event)
{
    on_btnRecvStop_clicked();
}


void FileCntDlg::on_btnRecvStop_clicked()
{
    myCntSocket->abort();
    myLocPathFile->close();
    close();
}

void FileCntDlg::getLocPath(QString lpath)
{
    myLocPathFile = new QFile(lpath);
}

void FileCntDlg::getSrvAddr(QHostAddress saddr)
{
    mySrvAddr = saddr;
    createConnToSrv();
}
