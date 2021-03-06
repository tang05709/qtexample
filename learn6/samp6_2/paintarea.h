#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape{Line, Rectangle, RoundRect, Ellipse, Polygon, Polyline, Points, Arc, Path, Text, Pixmap};
    explicit PaintArea(QWidget *parent = nullptr);
    void setShape(Shape);
    void setPen(QPen);
    void setBrush(QBrush);
    void setFillRule(Qt::FillRule);
    void paintEvent(QPaintEvent *event) override;

signals:

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    Qt::FillRule fillRule;

};

#endif // PAINTAREA_H
