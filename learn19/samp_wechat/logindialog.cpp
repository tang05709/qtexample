#include "logindialog.h"
#include "ui_logindialog.h"
#include <QFile>
#include <QDomElement>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->lePwd->setFocus();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::showWechatWindow()
{
    QFile file("userlog.xml");
    myDoc.setContent(&file);
    QDomElement root = myDoc.documentElement();
    if (root.hasChildNodes()) {
        QDomNodeList userList = root.childNodes();
        bool exist = false;
        for (int i = 0; i < userList.count(); i++) {
            QDomNode user = userList.at(i);
            QDomNodeList record = user.childNodes();
            // 用户名和密码
            QString uname = record.at(0).toElement().text();
            QString pword = record.at(1).toElement().text();
            if (uname == ui->leUser->text()) {
                exist = true;
                if (!(pword == ui->lePwd->text())) {
                    QMessageBox::warning(0, tr("提示"), tr("用户名或密码错误"));
                    ui->leUser->clear();
                    ui->lePwd->clear();
                    ui->leUser->setFocus();
                    return;
                }
            }
        }
        if (!exist) {
            QMessageBox::warning(0, tr("提示"), tr("用户名或密码错误"));
            ui->leUser->clear();
            ui->lePwd->clear();
            ui->leUser->setFocus();
            return;
        }
        wechatWindow = new MainWindow(0);
        wechatWindow->setWindowTitle(ui->leUser->text());
        wechatWindow->show();
    } else {
        QMessageBox::warning(0, tr("提示"), tr("打开文件错误"));
        ui->leUser->clear();
        ui->lePwd->clear();
        ui->leUser->setFocus();
        return;
    }
}

void LoginDialog::on_btnLogin_clicked()
{
    showWechatWindow();
}
