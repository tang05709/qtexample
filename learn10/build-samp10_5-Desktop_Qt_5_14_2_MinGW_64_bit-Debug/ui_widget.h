/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLineEdit *leMsg;
    QPushButton *btnSend;
    QLabel *labName;
    QLineEdit *leName;
    QLabel *labAddr;
    QLineEdit *leAddr;
    QLabel *labPort;
    QLineEdit *lePort;
    QPushButton *btnJoinRoom;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 258, 461));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 3);

        leMsg = new QLineEdit(widget);
        leMsg->setObjectName(QString::fromUtf8("leMsg"));

        gridLayout->addWidget(leMsg, 1, 0, 1, 2);

        btnSend = new QPushButton(widget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));

        gridLayout->addWidget(btnSend, 1, 2, 1, 1);

        labName = new QLabel(widget);
        labName->setObjectName(QString::fromUtf8("labName"));

        gridLayout->addWidget(labName, 2, 0, 1, 1);

        leName = new QLineEdit(widget);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 2, 1, 1, 2);

        labAddr = new QLabel(widget);
        labAddr->setObjectName(QString::fromUtf8("labAddr"));

        gridLayout->addWidget(labAddr, 3, 0, 1, 1);

        leAddr = new QLineEdit(widget);
        leAddr->setObjectName(QString::fromUtf8("leAddr"));

        gridLayout->addWidget(leAddr, 3, 1, 1, 2);

        labPort = new QLabel(widget);
        labPort->setObjectName(QString::fromUtf8("labPort"));

        gridLayout->addWidget(labPort, 4, 0, 1, 1);

        lePort = new QLineEdit(widget);
        lePort->setObjectName(QString::fromUtf8("lePort"));

        gridLayout->addWidget(lePort, 4, 1, 1, 2);

        btnJoinRoom = new QPushButton(widget);
        btnJoinRoom->setObjectName(QString::fromUtf8("btnJoinRoom"));

        gridLayout->addWidget(btnJoinRoom, 5, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        labName->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labAddr->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        labPort->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\357\274\232", nullptr));
        btnJoinRoom->setText(QCoreApplication::translate("Widget", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
