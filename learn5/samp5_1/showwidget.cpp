#include "showwidget.h"
#include <QHBoxLayout>

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    labImage = new QLabel;
    labImage->setScaledContents(true);
    text = new QTextEdit;
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(labImage);
    mainLayout->addWidget(text);
}
