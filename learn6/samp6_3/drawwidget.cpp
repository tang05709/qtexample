#include "drawwidget.h"
#include <QMouseEvent>
#include <QPainter>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600, 400);
}

void DrawWidget::setStyle(int s)
{
    style = s;
}

void DrawWidget::setWidth(int w)
{
    weight = w;
}

void DrawWidget::setColor(QColor c)
{
    color = c;
}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style); // 设置画笔线型
    pen.setWidth(weight); // 设置画笔线宽
    pen.setColor(color); // 设置画笔颜色
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos, event->pos());
    painter->end();
    startPos = event->pos();
    update();
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0, 0), *pix);
}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if (height() > pix->height() || width() > pix->width()) {
        QPixmap *newPix = new QPixmap(size()); //创建一个新的QPixmp对象
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0, 0), *pix); // 在newPix中绘制原pi中的内容
        pix = newPix; // 将newPix赋值给pix作为新的绘图接收对象
    }
    QWidget::resizeEvent(event);
}

void DrawWidget::clear()
{
    QPixmap *clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}
