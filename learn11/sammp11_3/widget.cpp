#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    image1.load(":/images/pkq1.png");
    ui->label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label1->setPixmap(QPixmap::fromImage(image1));

    image2.load(":/images/pkq2.png");
    ui->label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label2->setPixmap(QPixmap::fromImage(image2));

    image3.load(":/images/pkq3.png");
    ui->label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label3->setPixmap(QPixmap::fromImage(image3));

    // 添加时间过滤器，指定整个窗体为监视事件的对象，可以使用removeEventFilter()解除已添加的事件过滤器
    ui->label1->installEventFilter(this);
    ui->label2->installEventFilter(this);
    ui->label3->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    // 判断当前发生事件的对象
    if (watched == ui->label1) {
        // 判断事件的类型
        if (event->type() == QEvent::MouseButtonPress) {
            // 将事件event转化为鼠标事件
            // QMouseEvent *mouseEvent = (QMouseEvent*)event;
            // 显示缩小的图片
            QMatrix matrix;
            matrix.scale(1.2, 1.2);
            QImage tmpImage = image1.transformed(matrix);
            ui->label1->setPixmap(QPixmap::fromImage(tmpImage));
        }
        // 鼠标释放，恢复图片大小
        if (event->type() == QEvent::MouseButtonRelease) {
            ui->label1->setPixmap(QPixmap::fromImage(image1));
        }
    } else if (watched == ui->label2) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMatrix matrix;
            matrix.scale(1.2, 1.2);
            QImage tmpImage = image2.transformed(matrix);
            ui->label2->setPixmap(QPixmap::fromImage(tmpImage));
        }
        if (event->type() == QEvent::MouseButtonRelease) {
            ui->label2->setPixmap(QPixmap::fromImage(image2));
        }
    } else if (watched == ui->label3) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMatrix matrix;
            matrix.scale(1.2, 1.2);
            QImage tmpImage = image3.transformed(matrix);
            ui->label3->setPixmap(QPixmap::fromImage(tmpImage));
        }
        if (event->type() == QEvent::MouseButtonRelease) {
            ui->label3->setPixmap(QPixmap::fromImage(image3));
        }
    }
    return false;
}
