#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    port = 8010;
    ui->lePort->setText(QString::number(port));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCreateRoom_clicked()
{
    server = new Server(this, port);
    connect(server, SIGNAL(updateServer(QString, int)), this, SLOT(updateServer(QString, int)));
    ui->btnCreateRoom->setEnabled(false);
}

void Widget::updateServer(QString msg, int length)
{
    ui->listWidget->addItem(msg.left(length));
}
