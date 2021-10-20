#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    status = false;
    port = 8081;
    ui->lePort->setText(QString::number(port));
    serverIp = new QHostAddress();
    ui->btnSend->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnJoinRoom_clicked()
{
    if (!status) {
        QString ip = ui->leAddr->text();
        if (!serverIp->setAddress(ip)) {
            QMessageBox::information(this, tr("error"), tr("server ip address error"));
            return;
        }
        if (ui->leName->text() == "") {
            QMessageBox::information(this, tr("error"), tr("user name error"));
            return;
        }
        userName = ui->leName->text();
        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
        connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
        tcpSocket->connectToHost(*serverIp, port);
        status = true;
    } else {
        int length = 0;
        QString msg = userName + tr(": leave chat room");
        if ((length = tcpSocket->write(msg.toLatin1(), msg.length())) != msg.length()) {
            return;
        }
        tcpSocket->disconnectFromHost();
        status = false;
    }
}


void Widget::slotConnected()
{
    ui->btnSend->setEnabled(true);
    ui->btnJoinRoom->setText(tr("离开"));
    int length = 0;
    QString msg = userName + tr(": enter chat room");
    if ((length = tcpSocket->write(msg.toLatin1(), msg.length())) != msg.length()) {
        return;
    }
}

void Widget::slotDisconnected()
{
    ui->btnSend->setEnabled(false);
    ui->btnJoinRoom->setText(tr("进入聊天室"));
}

void Widget::dataReceived()
{
    while (tcpSocket->bytesAvailable() > 0) {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(datagram.data(), datagram.size());
        QString msg = datagram.data();
        ui->listWidget->addItem(msg.left(datagram.size()));
    }
}

void Widget::on_btnSend_clicked()
{
    if (ui->leMsg->text() == "") {
        QMessageBox::information(this, tr("error"), tr("message error"));
        return;
    }
    QString msg = userName + ": " + ui->leMsg->text();
    tcpSocket->write(msg.toLatin1(), msg.length());
    ui->leMsg->clear();
}
