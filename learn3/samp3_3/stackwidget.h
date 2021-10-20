#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>

class StackWidget : public QWidget
{
    Q_OBJECT

public:
    StackWidget(QWidget *parent = nullptr);
    ~StackWidget();

private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
};
#endif // STACKWIDGET_H
