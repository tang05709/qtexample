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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *listWidget;
    QLineEdit *lePort;
    QLabel *labPort;
    QPushButton *btnCreateRoom;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(70, 30, 431, 331));
        lePort = new QLineEdit(Widget);
        lePort->setObjectName(QString::fromUtf8("lePort"));
        lePort->setGeometry(QRect(150, 390, 351, 20));
        labPort = new QLabel(Widget);
        labPort->setObjectName(QString::fromUtf8("labPort"));
        labPort->setGeometry(QRect(70, 390, 54, 12));
        btnCreateRoom = new QPushButton(Widget);
        btnCreateRoom->setObjectName(QString::fromUtf8("btnCreateRoom"));
        btnCreateRoom->setGeometry(QRect(70, 440, 431, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        labPort->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\357\274\232", nullptr));
        btnCreateRoom->setText(QCoreApplication::translate("Widget", "\345\210\233\345\273\272\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
