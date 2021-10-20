#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QStackedWidget>
#include <QPushButton>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"


class UserWidget : public QFrame
{
    Q_OBJECT

public:
    UserWidget(QWidget *parent = nullptr);
    ~UserWidget();

    QStackedWidget *stack;
    QPushButton *btnAmend;
    QPushButton *btnClose;

    BaseInfo *baseInfo;
    Contact *contact;
    Detail *detail;
};
#endif // USERWIDGET_H
