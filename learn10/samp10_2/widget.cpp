#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    port = 5555;
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeout()
{
    QString msg = ui->leMsg->text();
    int length = 0;
    if (msg == "") {
        return ;
    }
    length = udpSocket->writeDatagram(msg.toLatin1(), msg.length(), QHostAddress::Broadcast, port);
    if (length != msg.length()) {
        return ;
    }
}

void Widget::on_btnStart_clicked()
{
    if (!isStarted) {
        ui->btnStart->setText(tr("停止"));
        timer->start(1000);
        isStarted = true;
    } else {
        ui->btnStart->setText(tr("开始"));
        isStarted = false;
        timer->stop();
    }
}
