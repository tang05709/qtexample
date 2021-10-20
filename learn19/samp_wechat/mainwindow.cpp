#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    myUdpSocket = new QUdpSocket(this);
    myUdpPort = 23232;
    myUdpSocket->bind(myUdpPort, QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(myUdpSocket, SIGNAL(readyRead()), this, SLOT(recvAndProcessChatMsg()));
    mySrv = new FileSrvDlg(this);
    connect(mySrv, SIGNAL(sendFileName(QString)), this, SLOT(getSfileName(QString)));
}

void MainWindow::on_btnSearch_clicked()
{
    myName = this->windowTitle();
    ui->labUser->setText(myName);
    sendChatMsg(OnLine);
}

void MainWindow::sendChatMsg(ChatMsgType msgType, QString rmtName)
{
    QByteArray qba;
    QDataStream write(&qba, QIODevice::WriteOnly);
    QString locHostIp = getLocHostIp();
    QString locChatMsg = getLocChatMsg();
    write << msgType << myName;
    switch (msgType) {
    case ChatMsg:
        write << locHostIp << locChatMsg;
        break;
    case OnLine:
        write << locHostIp;
        break;
    case OffLine:
        break;
    case SfileName:
        write << locHostIp << rmtName << myFileName;
        break;
    case RefFile:
        write << locHostIp << rmtName;
        break;
    }
    myUdpSocket->writeDatagram(qba, qba.length(), QHostAddress::Broadcast, myUdpPort);
}


void MainWindow::recvAndProcessChatMsg()
{
    while (myUdpSocket->hasPendingDatagrams()) {
        QByteArray qba;
        qba.resize(myUdpSocket->pendingDatagramSize());
        myUdpSocket->readDatagram(qba.data(), qba.size());
        QDataStream read(&qba, QIODevice::ReadOnly);
        int msgType;
        read >> msgType;
        QString name, hostip, chatmsg, rname, fname;
        QString curtime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch (msgType) {
        case ChatMsg:
            read >> name >> hostip >> chatmsg;
            ui->browserChatText->setTextColor(Qt::darkGreen);
            ui->browserChatText->setCurrentFont(QFont("Times New Roman", 14));
            ui->browserChatText->append("[" + name + "]" + curtime);
            break;
        case OnLine:
            read >> name >> hostip;
            onLine(name, curtime);
            break;
        case OffLine:
            read >> name;
            offLine(name, curtime);
            break;
        case SfileName:
            read >> name >> hostip >> rname >> fname;
            recvFileName(name, hostip, rname, fname);
            break;
        case RefFile:
            read >> name >> hostip >> rname;
            if (myName == rname) mySrv->cntRefused();
            break;
        }

    }
}


void MainWindow::onLine(QString name, QString time)
{
    bool notExist = ui->twgUserList->findItems(name, Qt::MatchExactly).isEmpty();
    if (notExist) {
        QTableWidgetItem *newUser = new QTableWidgetItem(name);
        ui->twgUserList->insertRow(0);
        ui->twgUserList->setItem(0, 0, newUser);
        ui->browserChatText->setTextColor(Qt::gray);
        ui->browserChatText->setCurrentFont(QFont("Times New Roman", 12));
        ui->browserChatText->append(tr("%1 %2 上线！").arg(time).arg(name));
        sendChatMsg(OnLine);
    }
}

void MainWindow::offLine(QString name, QString time)
{
    int row = ui->twgUserList->findItems(name, Qt::MatchExactly).first()->row();
    ui->twgUserList->removeRow(row);
    ui->browserChatText->setTextColor(Qt::gray);
    ui->browserChatText->setCurrentFont(QFont("Times New Roman", 12));
    ui->browserChatText->append(tr("%1 %2 离线!").arg(time).arg(name));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    sendChatMsg(OffLine);
}

QString MainWindow::getLocHostIp()
{
    QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
    foreach (QHostAddress addr, addrList) {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol) {
            return addr.toString();
        }
    }
    return 0;
}

QString MainWindow::getLocChatMsg()
{
    QString chatmsg = ui->teChat->toHtml();
    ui->teChat->clear();
    ui->teChat->setFocus();
    return chatmsg;
}

void MainWindow::getSfileName(QString fname)
{
    myFileName = fname;
    int row = ui->twgUserList->currentRow();
    QString rmtName = ui->twgUserList->item(row, 0)->text();
    sendChatMsg(SfileName, rmtName);
}

void MainWindow::recvFileName(QString name, QString hostip, QString rmtname, QString filename)
{
    if (myName == rmtname) {
        int result = QMessageBox::information(this,
                                              tr("收到文件"),
                                              tr("好友%1给你发送文件：\r\n%2, 是否接收？").arg(name).arg(filename),
                                              QMessageBox::Yes,
                                              QMessageBox::No);
        if (result == QMessageBox::Yes) {
            QString fname = QFileDialog::getSaveFileName(0, tr("保存"), filename);
            if (!fname.isEmpty()) {
                FileCntDlg *fcnt = new FileCntDlg(this);
                fcnt->getLocPath(fname);
                fcnt->getSrvAddr(QHostAddress(hostip));
                fcnt->show();
            }
        } else {
            sendChatMsg(RefFile, name);
        }
    }
}

void MainWindow::on_btnTrans_clicked()
{
    if (ui->twgUserList->selectedItems().isEmpty()) {
        QMessageBox::warning(0, tr("选择好友"), tr("请先选择文件接收方"), QMessageBox::Ok);
        return;
    }
    mySrv->show();
}

void MainWindow::on_btnSendMsg_clicked()
{
    sendChatMsg(ChatMsg);
}
