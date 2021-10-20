#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "tcpserversocket.h"
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr, int port = 0);
    QList<TcpServerSocket*> tcpServerSocketList;
signals:
    void updateServer(QString, int);
public slots:
    void updateClients(QString, int);
    void slotDisconnected(int);

protected:
    void incomingConnection(qintptr handle) override;
};

#endif // SERVER_H
