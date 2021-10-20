#include "dialog.h"
#include "ui_dialog.h"
#include "timeserver.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    count = 0;
    timeServer = new TimeServer(this);
    if (!timeServer->listen()) {
        QMessageBox::critical(this, tr("多线程时间服务器"), tr("无法启动服务：%1").arg(timeServer->errorString()));
        close();
        return;
    }
    ui->labPortValue->setText(QString::number(timeServer->serverPort()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnQuit_clicked()
{
    close();
}

void Dialog::slotShow()
{
    ui->labCount->setText(QString::number(++count));
}
