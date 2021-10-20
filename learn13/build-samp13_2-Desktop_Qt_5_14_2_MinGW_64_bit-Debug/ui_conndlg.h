/********************************************************************************
** Form generated from reading UI file 'conndlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNDLG_H
#define UI_CONNDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnDlg
{
public:
    QLabel *labStatus;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnConnect;
    QPushButton *btnQuit;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *labDriver;
    QComboBox *cmbDriver;
    QLabel *labDatabase;
    QLineEdit *leDatabase;
    QLabel *labUser;
    QLineEdit *leUser;
    QLabel *labPassword;
    QLineEdit *lePassword;
    QLabel *labHost;
    QLineEdit *leHost;
    QLabel *labPort;
    QSpinBox *spbPort;

    void setupUi(QDialog *ConnDlg)
    {
        if (ConnDlg->objectName().isEmpty())
            ConnDlg->setObjectName(QString::fromUtf8("ConnDlg"));
        ConnDlg->resize(285, 300);
        labStatus = new QLabel(ConnDlg);
        labStatus->setObjectName(QString::fromUtf8("labStatus"));
        labStatus->setGeometry(QRect(30, 220, 221, 21));
        widget = new QWidget(ConnDlg);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 260, 221, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnConnect = new QPushButton(widget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        horizontalLayout->addWidget(btnConnect);

        btnQuit = new QPushButton(widget);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));

        horizontalLayout->addWidget(btnQuit);

        widget1 = new QWidget(ConnDlg);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(30, 20, 221, 191));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labDriver = new QLabel(widget1);
        labDriver->setObjectName(QString::fromUtf8("labDriver"));

        gridLayout->addWidget(labDriver, 0, 0, 1, 1);

        cmbDriver = new QComboBox(widget1);
        cmbDriver->setObjectName(QString::fromUtf8("cmbDriver"));

        gridLayout->addWidget(cmbDriver, 0, 1, 1, 1);

        labDatabase = new QLabel(widget1);
        labDatabase->setObjectName(QString::fromUtf8("labDatabase"));

        gridLayout->addWidget(labDatabase, 1, 0, 1, 1);

        leDatabase = new QLineEdit(widget1);
        leDatabase->setObjectName(QString::fromUtf8("leDatabase"));

        gridLayout->addWidget(leDatabase, 1, 1, 1, 1);

        labUser = new QLabel(widget1);
        labUser->setObjectName(QString::fromUtf8("labUser"));

        gridLayout->addWidget(labUser, 2, 0, 1, 1);

        leUser = new QLineEdit(widget1);
        leUser->setObjectName(QString::fromUtf8("leUser"));

        gridLayout->addWidget(leUser, 2, 1, 1, 1);

        labPassword = new QLabel(widget1);
        labPassword->setObjectName(QString::fromUtf8("labPassword"));

        gridLayout->addWidget(labPassword, 3, 0, 1, 1);

        lePassword = new QLineEdit(widget1);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 3, 1, 1, 1);

        labHost = new QLabel(widget1);
        labHost->setObjectName(QString::fromUtf8("labHost"));

        gridLayout->addWidget(labHost, 4, 0, 1, 1);

        leHost = new QLineEdit(widget1);
        leHost->setObjectName(QString::fromUtf8("leHost"));

        gridLayout->addWidget(leHost, 4, 1, 1, 1);

        labPort = new QLabel(widget1);
        labPort->setObjectName(QString::fromUtf8("labPort"));

        gridLayout->addWidget(labPort, 5, 0, 1, 1);

        spbPort = new QSpinBox(widget1);
        spbPort->setObjectName(QString::fromUtf8("spbPort"));

        gridLayout->addWidget(spbPort, 5, 1, 1, 1);


        retranslateUi(ConnDlg);

        QMetaObject::connectSlotsByName(ConnDlg);
    } // setupUi

    void retranslateUi(QDialog *ConnDlg)
    {
        ConnDlg->setWindowTitle(QCoreApplication::translate("ConnDlg", "Dialog", nullptr));
        labStatus->setText(QCoreApplication::translate("ConnDlg", "\346\255\243\346\200\201\357\274\232", nullptr));
        btnConnect->setText(QCoreApplication::translate("ConnDlg", "\350\277\236\346\216\245", nullptr));
        btnQuit->setText(QCoreApplication::translate("ConnDlg", "\351\200\200\345\207\272", nullptr));
        labDriver->setText(QCoreApplication::translate("ConnDlg", "\351\251\261\345\212\250\357\274\232", nullptr));
        labDatabase->setText(QCoreApplication::translate("ConnDlg", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        labUser->setText(QCoreApplication::translate("ConnDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labPassword->setText(QCoreApplication::translate("ConnDlg", "\345\257\206\347\240\201\357\274\232", nullptr));
        labHost->setText(QCoreApplication::translate("ConnDlg", "\344\270\273\346\234\272\345\220\215\357\274\232", nullptr));
        labPort->setText(QCoreApplication::translate("ConnDlg", "\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnDlg: public Ui_ConnDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNDLG_H
