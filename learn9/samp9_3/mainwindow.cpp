#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDataStream>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fileFun();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileFun()
{
    QFile file("binary.dat");
    // 将二进制数据写入数据流
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&file);
    out << QString(tr("Donald:"));
    out << QDate::fromString("1996/09/25", "yyyy/MM/dd");
    out << qint32(23);
    file.close();

    // 从文件中读取数据
    file.setFileName("binary.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        ui->label->setText(tr("error"));
        return;
    }
    QDataStream in(&file);
    QString name;
    QDate birthday;
    qint32 age;
    in >> name >> birthday >> age;
    ui->label->setText(QString("Name: %1; Birthday: %2; Age: %3").arg(name).arg(birthday.toString()).arg(age));
    file.close();
}
