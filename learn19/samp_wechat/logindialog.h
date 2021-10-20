#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDomComment>
#include "mainwindow.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void showWechatWindow();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginDialog *ui;

    MainWindow *wechatWindow;
    QDomDocument myDoc;
};

#endif // LOGINDIALOG_H
