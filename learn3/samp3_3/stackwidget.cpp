#include "stackwidget.h"
#include <QHBoxLayout>

StackWidget::StackWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("StackedWidget"));
    list = new QListWidget(this);
    list->insertItem(0, tr("Window1"));
    list->insertItem(1, tr("Window2"));
    list->insertItem(2, tr("Window3"));

    label1 = new QLabel(tr("WindowText1"));
    label2 = new QLabel(tr("WindowText2"));
    label3 = new QLabel(tr("WindowText3"));

    stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(5);
    layout->setMargin(5);
    layout->addWidget(list);
    layout->addWidget(stack, 0, Qt::AlignHCenter);
    layout->setStretchFactor(list, 1);
    layout->setStretchFactor(stack, 3);

    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

StackWidget::~StackWidget()
{
}

