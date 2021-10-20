#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(400, 300);
    ui->leUser->setFocus();
    /*QString pwd = strToMD5("123456");
    QSqlQuery query;
    QString sql = "insert into member (`MemberId`, `Password`, `Name`, `Sex`, `Email`, `Address`, `Phone`, `RegisterDate`)";
    sql += "values(1, '"+pwd+"', 'Donald', 1, 'admin@admin.com', 'chengdu', '15874748585', '2021-10-12')";
    query.exec(sql);*/

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnLogin_clicked()
{
    if (!ui->lePassword->text().isEmpty() && !ui->leUser->text().isEmpty()) {
        QSqlQuery query;
        query.prepare("select Name, Password from member where name=?");
        query.bindValue(0, ui->leUser->text());
        query.exec();
        if (query.next()) {
            QString pwdMD5 = strToMD5(ui->lePassword->text());
            if (query.value(1).toString() == pwdMD5) {
                QDialog::accept();
            }
        } else {
            QMessageBox::warning(this, tr("用户名或密码错误"), tr("请重新输入用户名密码"), QMessageBox::Ok);
            ui->lePassword->clear();
            ui->lePassword->setFocus();
        }
    } else {
        ui->lePassword->setFocus();
    }
}

void LoginDialog::on_btnQuit_clicked()
{
    QDialog::reject();
}

QString LoginDialog::strToMD5(QString str)
{
    QString strMD5;
    QByteArray qba;
    qba = QCryptographicHash::hash(str.toLatin1(), QCryptographicHash::Md5);
    strMD5.append(qba.toHex());
    return strMD5;
}
