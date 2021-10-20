#include "filesrvdlg.h"
#include "ui_filesrvdlg.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>

FileSrvDlg::FileSrvDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSrvDlg)
{
    ui->setupUi(this);

    myTcpSrv = new QTcpServer(this);
    mySrvPort = 5555;
    connect(myTcpSrv, SIGNAL(newConnection()), this, SLOT(sndChatMsg()));
    myTcpSrv->close();
    myTotalBytes = 0;
    mySendBytes = 0;
    myBytesTobeSend = 0;
    myPayloadSize = 64 * 1024;
    ui->btnChooseFile->setEnabled(true);
    ui->btnSend->setEnabled(false);

}

FileSrvDlg::~FileSrvDlg()
{
    delete ui;
}

void FileSrvDlg::sndChatMsg()
{
    ui->btnSend->setEnabled(false);
    mySrvSocket = myTcpSrv->nextPendingConnection();
    connect(mySrvSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(refreshProgress(qint64)));
    myLocPathFile = new QFile(myPathFile);
    myLocPathFile->open((QFile::ReadOnly));
    myTotalBytes = myLocPathFile->size();
    QDataStream sendOut(&myOutputBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_14);
    myTime.start();
    QString curFile = myPathFile.right(myPathFile.size() - myPathFile.lastIndexOf("/") - 1);
    sendOut << qint64(0) << qint64(0) << curFile;
    myTotalBytes += myOutputBlock.size();
    sendOut.device()->seek(0);
    sendOut << myTotalBytes << qint64((myOutputBlock.size() - sizeof(qint64) * 2));
    myBytesTobeSend = myTotalBytes - mySrvSocket->write(myOutputBlock);
    myOutputBlock.resize(0);

}

void FileSrvDlg::refreshProgress(qint64 bynum)
{
    qApp->processEvents();
    mySendBytes += (int)bynum;
    if (myBytesTobeSend > 0) {
        myOutputBlock = myLocPathFile->read(qMin(myBytesTobeSend, myPayloadSize));
        myBytesTobeSend -= (int)mySrvSocket->write(myOutputBlock);
        myOutputBlock.resize(0);
    } else {
        myLocPathFile->close();
    }
    ui->progressSend->setMaximum(myTotalBytes);
    ui->progressSend->setValue(mySendBytes);
    ui->leSendSize->setText(tr("%1").arg(myTotalBytes / (1024 * 1024)) + "MB");
    ui->leSendCurrentSize->setText(tr("%1").arg(mySendBytes / (1024 * 1024)) + "MB");
    if (mySendBytes == myTotalBytes) {
        myLocPathFile->close();
        myTcpSrv->close();
        QMessageBox::information(0, tr("完毕"), tr("文件传输完成"));
    }
}

void FileSrvDlg::cntRefused()
{
    myTcpSrv->close();
    QMessageBox::warning(0, tr("提示"), tr("对方拒收文件"));
}

void FileSrvDlg::on_btnChooseFile_clicked()
{
    myPathFile = QFileDialog::getOpenFileName(this);
    if (!myPathFile.isEmpty()) {
        myFileName = myPathFile.right(myPathFile.size() - myPathFile.lastIndexOf("/") - 1);
        ui->leSend->setText(myFileName);
        ui->btnSend->setEnabled(true);
        ui->btnChooseFile->setEnabled(false);
    }
}

void FileSrvDlg::on_btnSend_clicked()
{
    if (!myTcpSrv->listen(QHostAddress::Any, mySrvPort)) {
        QMessageBox::warning(0, tr("异常"), tr("打开tcp端口出错，请检查网络"));
        close();
        return;
    }
    emit sendFileName(myFileName);
}

void FileSrvDlg::on_btnStopSend_clicked()
{
    if (myTcpSrv->isListening()) {
        myTcpSrv->close();
        myLocPathFile->close();
        mySrvSocket->abort();
    }
    close();
}

void FileSrvDlg::closeEvent(QCloseEvent *event)
{
    on_btnStopSend_clicked();
}

