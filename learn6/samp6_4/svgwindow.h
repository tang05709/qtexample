#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include <QScrollArea>
#include "svgwidget.h"

class SvgWindow : public QScrollArea
{
    Q_OBJECT
public:
    SvgWindow(QWidget *parent = nullptr);
    void setFile(QString);
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;

private:
    SvgWidget *svgWidget;
    QPoint mousePressPos;
    QPoint scrollBarValuesOnMousePress;
};

#endif // SVGWINDOW_H
