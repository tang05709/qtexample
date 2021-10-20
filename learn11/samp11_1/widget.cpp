#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
    if (event->button() == Qt::LeftButton) {
         ui->labStatus->setText(tr("Left Button"));
    }
    else if (event->button() == Qt::RightButton) {
         ui->labStatus->setText(tr("Right Button"));
    }
    else if (event->button() == Qt::MidButton) {
         ui->labStatus->setText(tr("Middle Button"));
    }
    ui->labMousePos->setText(str);

}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
    ui->labMousePos->setText(str);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
    ui->labMousePos->setText(tr("释放：") + str);
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")";
    ui->labMousePos->setText(tr("Double Click：") + str);
}
