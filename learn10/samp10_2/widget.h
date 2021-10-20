#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void timeout();
private slots:
    void on_btnStart_clicked();

private:
    Ui::Widget *ui;
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
};
#endif // WIDGET_H
