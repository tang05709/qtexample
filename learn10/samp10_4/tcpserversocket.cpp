#include "tcpserversocket.h"

TcpServerSocket::TcpServerSocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(this, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
}

void TcpServerSocket::dataRecdived()
{
    while (bytesAvailable() > 0) {
        int length = bytesAvailable();
        char buf[1024];
        read(buf, length);
        QString msg = buf;
        emit updateClients(msg, length);
    }
}

void TcpServerSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
