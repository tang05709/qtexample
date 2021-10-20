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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *labPortTxt;
    QLabel *labPortValue;
    QPushButton *btnQuit;
    QLabel *labCount;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        labPortTxt = new QLabel(Dialog);
        labPortTxt->setObjectName(QString::fromUtf8("labPortTxt"));
        labPortTxt->setGeometry(QRect(50, 40, 71, 21));
        labPortValue = new QLabel(Dialog);
        labPortValue->setObjectName(QString::fromUtf8("labPortValue"));
        labPortValue->setGeometry(QRect(130, 40, 161, 21));
        btnQuit = new QPushButton(Dialog);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));
        btnQuit->setGeometry(QRect(50, 80, 131, 20));
        labCount = new QLabel(Dialog);
        labCount->setObjectName(QString::fromUtf8("labCount"));
        labCount->setGeometry(QRect(320, 40, 54, 16));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        labPortTxt->setText(QCoreApplication::translate("Dialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        labPortValue->setText(QString());
        btnQuit->setText(QCoreApplication::translate("Dialog", "\351\200\200\345\207\272", nullptr));
        labCount->setText(QCoreApplication::translate("Dialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
