#ifndef FILESRVDLG_H
#define FILESRVDLG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTime>

namespace Ui {
class FileSrvDlg;
}

class FileSrvDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FileSrvDlg(QWidget *parent = nullptr);
    ~FileSrvDlg();

    void cntRefused(); // 拒绝接收文件处理
protected:
    void closeEvent(QCloseEvent *);

signals:
    void sendFileName(QString name);
private slots:
    void sndChatMsg(); // 发送消息
    void refreshProgress(qint64 bynum); // 刷新服务器进度条
    void on_btnChooseFile_clicked();

    void on_btnSend_clicked();

    void on_btnStopSend_clicked();

private:
    Ui::FileSrvDlg *ui;

    QTcpServer *myTcpSrv;
    QTcpSocket *mySrvSocket;
    qint16 mySrvPort;

    QFile *myLocPathFile;
    QString myPathFile; // 含路径的本地待发送文件名
    QString myFileName; // 文件名称

    qint64 myTotalBytes; // 总共要发送的字节数
    qint64 mySendBytes; // 已发送的字节数
    qint64 myBytesTobeSend; // 剩余的字节数
    qint64 myPayloadSize; // 有效载荷

    QByteArray myOutputBlock; // 缓存一次发送的数据
    QTime myTime;

};

#endif // FILESRVDLG_H
