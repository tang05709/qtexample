#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnStop->setEnabled(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnStart_clicked()
{
    for (int i = 0; i < MAXSIZE; i++) {
        workThread[i] = new WorkThread();
    }
    for (int i = 0; i < MAXSIZE; i++) {
        workThread[i]->start();
    }
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
}

void Widget::on_btnStop_clicked()
{
    for (int i = 0; i < MAXSIZE; i++) {
        workThread[i]->terminate();
        workThread[i]->wait();
    }
}

void Widget::on_btnQuit_clicked()
{
    close();
}
