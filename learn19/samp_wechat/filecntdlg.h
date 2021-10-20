#ifndef FILECNTDLG_H
#define FILECNTDLG_H

#include <QDialog>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTime>
#include <QFile>

namespace Ui {
class FileCntDlg;
}

class FileCntDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FileCntDlg(QWidget *parent = nullptr);
    ~FileCntDlg();

    void getSrvAddr(QHostAddress saddr);
    void getLocPath(QString lpath);

protected:
    void closeEvent(QCloseEvent *) override;

private slots:
    void createConnToSrv();
    void readChatMsg();
    void on_btnRecvStop_clicked();

private:
    Ui::FileCntDlg *ui;

    QTcpSocket *myCntSocket;
    QHostAddress mySrvAddr;
    qint16 mySrvPort;

    QFile *myLocPathFile;
    QString myPathFile; // 含路径的本地待发送文件名
    QString myFileName; // 文件名称
    qint64 myFileNameSize; // 文件名大小

    qint64 myTotalBytes; // 总共要接收的字节数
    qint64 myRcvedBytes; // 已接收的字节数
    qint64 myBlockSize; // 缓冲块大小

    QByteArray myInputputBlock; // 缓存一次接收的数据
    QTime myTime;

};

#endif // FILECNTDLG_H
