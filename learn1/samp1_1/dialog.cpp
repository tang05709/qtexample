#include "dialog.h"
#include "ui_dialog.h"
#include <QtDebug>

const static double PI = 3.1416;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCount_clicked()
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->leRadius->text();
    qDebug() << valueStr;
    int valueInt = valueStr.toUInt(&ok);
    qDebug() << ok;
    if (ok) {
        double area = valueInt * valueInt * PI;
        ui->labResult->setText(tempStr.setNum(area));
    }
}
