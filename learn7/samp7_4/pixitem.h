#ifndef PIXITEM_H
#define PIXITEM_H

#include <QGraphicsItem>
class PixItem : public QGraphicsItem
{
public:
    PixItem(QPixmap *pixmap);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPixmap pix;
};

#endif // PIXITEM_H
