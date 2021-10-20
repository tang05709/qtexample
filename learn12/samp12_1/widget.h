#ifndef WIDGET_H
#define WIDGET_H
#define MAXSIZE 1
#include <QWidget>
#include "workthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnQuit_clicked();

private:
    Ui::Widget *ui;

    WorkThread *workThread[MAXSIZE];
};
#endif // WIDGET_H
