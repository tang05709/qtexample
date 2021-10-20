#include "widget.h"
#include "ui_widget.h"
#include <QHostInfo>
#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    getHostInformation();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnInfo_clicked()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for (int i = 0; i < list.count(); i++) {
        QNetworkInterface interface = list.at(i);
        ui->textEdit->append(tr("设备：") + interface.name());
        ui->textEdit->append(tr("硬件地址：") + interface.hardwareAddress());
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for (int j = 1; j < entryList.count(); j++) {
            QNetworkAddressEntry entry = entryList.at(j);
            ui->textEdit->append(tr("IP地址：") + entry.ip().toString());
            ui->textEdit->append(tr("子网掩码：") + entry.netmask().toString());
            ui->textEdit->append(tr("广播地址：") + entry.broadcast().toString());
        }
    }
}


void Widget::getHostInformation()
{
    QString localHostName = QHostInfo::localHostName();
    ui->leHostName->setText(localHostName);
    QHostInfo hostInfo = QHostInfo::fromName(localHostName);

    QList<QHostAddress> listAddrs = hostInfo.addresses();
    if (!listAddrs.isEmpty()) {
        ui->leIpAddr->setText(listAddrs.at(1).toString());
    }
}
