#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFile file("text.txt");
    if (file.open(QIODevice::ReadOnly)) {
        char buffer[2048];
        qint64 lineLen = file.readLine(buffer, sizeof(buffer));
        if (lineLen != -1) {
            ui->label->setText(buffer);
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

