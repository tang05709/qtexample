#include "svgwidget.h"
#include <QWheelEvent>

SvgWidget::SvgWidget(QWidget *parent) : QSvgWidget(parent)
{
    render = renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *event)
{
    const double diff = 0.1;
    QSize size = render->defaultSize();
    int width = size.width();
    int height = size.height();
    if (event->delta() > 0) {
        width = int(this->width() + this->width() * diff);
        height = int(this->height() + this->height() * diff);
    } else {
        width = int(this->width() - this->width() * diff);
        height = int(this->height() - this->height() * diff);
    }
    resize(width, height);
}

