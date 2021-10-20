#ifndef STARITEM_H
#define STARITEM_H

#include <QGraphicsItem>
#include <QPixmap>

class StarItem : public QGraphicsItem
{
public:
    StarItem();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPixmap pix;
};

#endif // STARITEM_H
