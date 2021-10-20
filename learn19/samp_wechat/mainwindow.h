#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QDomDocument>
#include "filesrvdlg.h"
#include "filecntdlg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ChatMsgType {
        ChatMsg, // 聊天内容
        OnLine,  // 用户上线
        OffLine, // 用户离线
        SfileName,  // 要传输的文件名
        RefFile  // 拒收文件
    };
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initMainWindow(); // c初始化窗口
    void onLine(QString name, QString time); // 新用户上线
    void offLine(QString name, QString time); // 用户离线
    void sendChatMsg(ChatMsgType msgType, QString rmtName = ""); // 发送消息
    QString getLocHostIp(); // 获取本端ip的地址
    QString getLocChatMsg(); // 获取本端聊天信息内容
    void recvFileName(QString name, QString hostip, QString rmtname, QString filename); // 接收文件

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void recvAndProcessChatMsg(); // 接收并处理UDP数据报
    void getSfileName(QString); // 获取文件名
    void on_btnSearch_clicked();

    void on_btnTrans_clicked();

    void on_btnSendMsg_clicked();

private:
    Ui::MainWindow *ui;

    QString myName = "";
    QUdpSocket *myUdpSocket;
    qint16 myUdpPort;
    QDomDocument myDoc;
    QString myFileName;
    FileSrvDlg *mySrv;

};
#endif // MAINWINDOW_H
