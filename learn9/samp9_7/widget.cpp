#include "widget.h"
#include "ui_widget.h"
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString path = QDir::currentPath();
    ui->labDir->setText(path);
    fsWatcher.addPath(path);
    connect(&fsWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(directoruChanged(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::directoruChanged(QString path)
{
    ui->labMsg->setText(tr("目录发生变化"));
}
