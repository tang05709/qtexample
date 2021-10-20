#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostAddress>
#include <QTcpSocket>

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
    void slotConnected();
    void slotDisconnected();
    void dataReceived();

private slots:
    void on_btnJoinRoom_clicked();

    void on_btnSend_clicked();

private:
    Ui::Widget *ui;

    bool  status;
    int port;
    QHostAddress *serverIp;
    QString userName;
    QTcpSocket *tcpSocket;
};
#endif // WIDGET_H
