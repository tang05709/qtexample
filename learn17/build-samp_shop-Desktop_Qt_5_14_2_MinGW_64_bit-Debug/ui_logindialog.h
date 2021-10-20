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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *labWelcome;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labUser;
    QLineEdit *leUser;
    QLabel *labPassword;
    QLineEdit *lePassword;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnLogin;
    QPushButton *btnQuit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(400, 300);
        labWelcome = new QLabel(LoginDialog);
        labWelcome->setObjectName(QString::fromUtf8("labWelcome"));
        labWelcome->setGeometry(QRect(110, 40, 171, 21));
        QFont font;
        font.setPointSize(16);
        labWelcome->setFont(font);
        widget = new QWidget(LoginDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 90, 231, 71));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labUser = new QLabel(widget);
        labUser->setObjectName(QString::fromUtf8("labUser"));

        gridLayout->addWidget(labUser, 0, 0, 1, 1);

        leUser = new QLineEdit(widget);
        leUser->setObjectName(QString::fromUtf8("leUser"));

        gridLayout->addWidget(leUser, 0, 1, 1, 1);

        labPassword = new QLabel(widget);
        labPassword->setObjectName(QString::fromUtf8("labPassword"));

        gridLayout->addWidget(labPassword, 1, 0, 1, 1);

        lePassword = new QLineEdit(widget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 1, 1, 1, 1);

        widget1 = new QWidget(LoginDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(80, 180, 232, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(70);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnLogin = new QPushButton(widget1);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        horizontalLayout->addWidget(btnLogin);

        btnQuit = new QPushButton(widget1);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));

        horizontalLayout->addWidget(btnQuit);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        labWelcome->setText(QCoreApplication::translate("LoginDialog", "\346\254\242\350\277\216\350\277\233\345\205\245\347\224\265\345\255\220\345\225\206\345\237\216", nullptr));
        labUser->setText(QCoreApplication::translate("LoginDialog", "\347\256\241\347\220\206\345\221\230\357\274\232", nullptr));
        labPassword->setText(QCoreApplication::translate("LoginDialog", "\345\257\206  \347\240\201\357\274\232", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        btnQuit->setText(QCoreApplication::translate("LoginDialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
