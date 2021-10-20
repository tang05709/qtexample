#include "server.h"

Server::Server(QObject *parent, int port) : QTcpServer(parent)
{
    listen(QHostAddress::Any, port);
}

void Server::incomingConnection(qintptr handle)
{
    TcpServerSocket *tcpServerSocket = new TcpServerSocket(this);

    connect(tcpServerSocket, SIGNAL(updateClients(Qstring, int)), this, SLOT(updateClients(QString, int)));
    connect(tcpServerSocket, SIGNAL(disconnected(int)), this, SLOT(slotDisconnected(int)));
    tcpServerSocket->setSocketDescriptor(socketDescriptor());
    tcpServerSocketList.append(tcpServerSocket);
}

void Server::updateClients(QString msg, int length)
{
    emit updateServer(msg, length);
    for (int i = 0; i < tcpServerSocketList.count(); i++) {
        QTcpSocket *item = tcpServerSocketList.at(i);
        if (item->write(msg.toLatin1(), length) != length) {
            continue;
        }
    }
}

void Server::slotDisconnected(int descriptor)
{
    for (int i = 0; i < tcpServerSocketList.count(); i++) {
        QTcpSocket *item = tcpServerSocketList.at(i);
        if (item->socketDescriptor() == descriptor) {
            tcpServerSocketList.removeAt(i);
            return;
        }
    }
}
