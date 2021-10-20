#ifndef TCPSERVERSOCKET_H
#define TCPSERVERSOCKET_H

#include <QTcpSocket>
class TcpServerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpServerSocket(QObject *parent = nullptr);

signals:
    void updateClients(QString, int);
    void disconnected(int);

protected slots:
    void dataRecdived();
    void slotDisconnected();
};

#endif // TCPSERVERSOCKET_H
