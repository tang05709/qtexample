#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>
#include <QGraphicsItem>

class FlashItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FlashItem(QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void timerEvent(QTimerEvent *event) override;

signals:

private:
    bool flash;
    QTimer *timer;

};

#endif // FLASHITEM_H
