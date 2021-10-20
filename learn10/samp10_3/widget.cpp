#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    port = 5555;
    udpSocket = new QUdpSocket(this);
    bool result = udpSocket->bind(port);
    if (!result) {
        ui->lbError->setText(tr("error"));
        return;
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::dataReceived()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString msg = datagram.data();
        ui->teMsg->insertPlainText(msg);
    }
}

void Widget::on_btnClose_clicked()
{
    close();
}
