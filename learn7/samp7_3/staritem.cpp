#include "staritem.h"
#include <QPainter>

StarItem::StarItem()
{
    pix.load(":/images/star2.png");
}

QRectF StarItem::boundingRect() const
{
    return QRectF(-pix.width() / 2, -pix.height() / 2, pix.width(), pix.height());
}

void StarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(), pix);
}
