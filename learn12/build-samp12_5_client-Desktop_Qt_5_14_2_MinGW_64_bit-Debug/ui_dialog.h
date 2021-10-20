/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labName;
    QLineEdit *leName;
    QLabel *labPort;
    QLineEdit *lePort;
    QDateTimeEdit *dateTimeEdit;
    QLabel *labError;
    QPushButton *btnGetTime;
    QPushButton *btnQuit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 231, 141));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labName = new QLabel(widget);
        labName->setObjectName(QString::fromUtf8("labName"));

        gridLayout->addWidget(labName, 0, 0, 1, 1);

        leName = new QLineEdit(widget);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 0, 1, 1, 2);

        labPort = new QLabel(widget);
        labPort->setObjectName(QString::fromUtf8("labPort"));

        gridLayout->addWidget(labPort, 1, 0, 1, 1);

        lePort = new QLineEdit(widget);
        lePort->setObjectName(QString::fromUtf8("lePort"));

        gridLayout->addWidget(lePort, 1, 1, 1, 2);

        dateTimeEdit = new QDateTimeEdit(widget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 2, 0, 1, 3);

        labError = new QLabel(widget);
        labError->setObjectName(QString::fromUtf8("labError"));

        gridLayout->addWidget(labError, 3, 0, 1, 3);

        btnGetTime = new QPushButton(widget);
        btnGetTime->setObjectName(QString::fromUtf8("btnGetTime"));

        gridLayout->addWidget(btnGetTime, 4, 0, 1, 2);

        btnQuit = new QPushButton(widget);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));

        gridLayout->addWidget(btnQuit, 4, 2, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        labName->setText(QCoreApplication::translate("Dialog", "\346\234\215\345\212\241\345\231\250\345\220\215\357\274\232", nullptr));
        labPort->setText(QCoreApplication::translate("Dialog", "\347\253\257\345\217\243\357\274\232", nullptr));
        labError->setText(QCoreApplication::translate("Dialog", "error", nullptr));
        btnGetTime->setText(QCoreApplication::translate("Dialog", "\350\216\267\345\217\226\346\227\266\351\227\264", nullptr));
        btnQuit->setText(QCoreApplication::translate("Dialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
