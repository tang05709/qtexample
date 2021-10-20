#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QCryptographicHash> // 包含md5算法

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    QString strToMD5(QString str); // 字符串md5加密

private slots:
    void on_btnLogin_clicked();

    void on_btnQuit_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
