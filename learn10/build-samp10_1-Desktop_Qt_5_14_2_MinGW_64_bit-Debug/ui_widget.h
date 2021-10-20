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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnInfo;
    QTextEdit *textEdit;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labHostName;
    QLineEdit *leHostName;
    QLabel *labIpAddr;
    QLineEdit *leIpAddr;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        btnInfo = new QPushButton(Widget);
        btnInfo->setObjectName(QString::fromUtf8("btnInfo"));
        btnInfo->setGeometry(QRect(100, 180, 291, 20));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(440, 70, 321, 281));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 70, 291, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labHostName = new QLabel(widget);
        labHostName->setObjectName(QString::fromUtf8("labHostName"));

        gridLayout->addWidget(labHostName, 0, 0, 1, 1);

        leHostName = new QLineEdit(widget);
        leHostName->setObjectName(QString::fromUtf8("leHostName"));

        gridLayout->addWidget(leHostName, 0, 1, 1, 1);

        labIpAddr = new QLabel(widget);
        labIpAddr->setObjectName(QString::fromUtf8("labIpAddr"));

        gridLayout->addWidget(labIpAddr, 1, 0, 1, 1);

        leIpAddr = new QLineEdit(widget);
        leIpAddr->setObjectName(QString::fromUtf8("leIpAddr"));

        gridLayout->addWidget(leIpAddr, 1, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnInfo->setText(QCoreApplication::translate("Widget", "\350\257\246\347\273\206", nullptr));
        labHostName->setText(QCoreApplication::translate("Widget", "\344\270\273\346\234\272\345\220\215\357\274\232", nullptr));
        labIpAddr->setText(QCoreApplication::translate("Widget", "IP\345\234\260\345\235\200\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
