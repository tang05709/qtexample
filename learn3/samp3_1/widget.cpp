#include "widget.h"
#include <QSplitter>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    QTextEdit *textLeft = new QTextEdit(tr("Left Widget"), splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);

    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    splitterRight->setOpaqueResize(false);
    QTextEdit *textUp = new QTextEdit(tr("Top Widget"), splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit *textBottm = new QTextEdit(tr("Bottom Widget"), splitterRight);
    textBottm->setAlignment(Qt::AlignHCenter);

    splitterMain->setStretchFactor(1, 1);
    splitterMain->setWindowTitle(tr("Splitter"));
    splitterMain->show();

}

Widget::~Widget()
{
}

