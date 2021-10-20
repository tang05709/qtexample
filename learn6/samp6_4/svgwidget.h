#ifndef SVGWIDGET_H
#define SVGWIDGET_H

#include <QSvgWidget>
#include <QSvgRenderer>

class SvgWidget : public QSvgWidget
{
    Q_OBJECT
public:
    SvgWidget(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *) override;

private:
    QSvgRenderer *render;
};

#endif // SVGWIDGET_H
