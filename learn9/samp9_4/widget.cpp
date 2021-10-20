#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString path = QDir::currentPath();
    du(path);
}

Widget::~Widget()
{
    delete ui;
}

qint64 Widget::du(const QString &path)
{
    QDir dir(path);
    qint64 size = 0;
    foreach (QFileInfo fileInfo, dir.entryInfoList(QDir::Files)) {
        size += fileInfo.size();
    }

    foreach (QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        size += du(path + QDir::separator() + subDir);
    }

    char unit= 'B';
    qint64 curSize = size;
    if (curSize > 1024) {
        curSize /= 1024;
        unit = 'M';
        if (curSize > 1024) {
            curSize /= 1024;
            unit = 'G';
        }
    }
    ui->label->setText(QString("size: %1 %2").arg(curSize).arg(unit));
    return size;
}
