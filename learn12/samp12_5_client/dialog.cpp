#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->leName, SIGNAL(textChanged(QString)), this, SLOT(enableGetBtn()));
    connect(ui->lePort, SIGNAL(textChanged(QString)), this, SLOT(enableGetBtn()));
    connect(ui->btnGetTime, SIGNAL(clicked()), this, SLOT(getTime()));

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readTime()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(showError(QAbstractSocket::SocketError)));
    ui->lePort->setFocus();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnQuit_clicked()
{
    close();
}

void Dialog::enableGetBtn()
{
    ui->btnGetTime->setEnabled(!ui->leName->text().isEmpty() && !ui->lePort->text().isEmpty());

}

void Dialog::getTime()
{
    ui->btnGetTime->setEnabled(false);
    time2u = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(ui->leName->text(), ui->lePort->text().toInt());
}

void Dialog::readTime()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_12);
    if (time2u == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(uint)) {
            return;
        }
        in >> time2u;
    }
    ui->dateTimeEdit->setDateTime(QDateTime::fromTime_t(time2u));
    ui->btnGetTime->setEnabled(true);
}

void Dialog::showError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        ui->labError->setText(tr("主机不可达"));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        ui->labError->setText(tr("连接拒绝"));
        break;
    default:
        ui->labError->setText(tcpSocket->errorString());
        break;
    }
    ui->btnGetTime->setEnabled(true);
}
