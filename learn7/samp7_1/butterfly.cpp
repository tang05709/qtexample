#include "butterfly.h"
#include <QPainter>
#include <math.h>

const static double PI = 301416;
Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up = true;
    pixUp .load(":/images/up.png");
    pixDown.load(":/images/down.png");
    startTimer(100);
}


QRectF Butterfly::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-pixUp.width() / 2 - adjust, -pixUp.height() / 2 - adjust, pixUp.width() + adjust * 2, pixUp.height() + adjust * 2);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (up) {
        painter->drawPixmap(boundingRect().topLeft(), pixUp);
        up = !up;
    } else {
        painter->drawPixmap(boundingRect().topLeft(), pixDown);
        up = !up;
    }
}

void Butterfly::timerEvent(QTimerEvent *event)
{
    qreal edgex = scene()->sceneRect().right() + boundingRect().width() / 2;
    qreal edgetop = scene()->sceneRect().top() + boundingRect().height() / 2;
    qreal edgebottom = scene()->sceneRect().bottom() + boundingRect().height() / 2;

    if (pos().x() >= edgex) {
        setPos(scene()->sceneRect().left(), pos().y());
    }
    if (pos().y() <= edgetop) {
        setPos(pos().x(), scene()->sceneRect().bottom());
    }
    if (pos().y() >= edgebottom) {
        setPos(pos().x(), scene()->sceneRect().top());
    }
    angle += (qrand() % 10) / 20.0;
    qreal dx = fabs(sin(angle * PI) / 10.0);
    qreal dy = (qrand() % 20) - 10.0;
    setPos(mapToParent(dx, dy));
}
