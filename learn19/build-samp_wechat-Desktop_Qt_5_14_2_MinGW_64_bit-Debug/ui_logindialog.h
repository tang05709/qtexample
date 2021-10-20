/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *logo;
    QLineEdit *leUser;
    QLineEdit *lePwd;
    QPushButton *btnLogin;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(300, 300);
        logo = new QLabel(LoginDialog);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(110, 40, 60, 60));
        logo->setFrameShadow(QFrame::Sunken);
        logo->setTextFormat(Qt::AutoText);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/images/image/wechat.png")));
        logo->setScaledContents(true);
        leUser = new QLineEdit(LoginDialog);
        leUser->setObjectName(QString::fromUtf8("leUser"));
        leUser->setGeometry(QRect(90, 130, 120, 28));
        lePwd = new QLineEdit(LoginDialog);
        lePwd->setObjectName(QString::fromUtf8("lePwd"));
        lePwd->setGeometry(QRect(90, 170, 120, 28));
        btnLogin = new QPushButton(LoginDialog);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(70, 210, 160, 40));
        btnLogin->setFlat(true);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        logo->setText(QString());
        btnLogin->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
