/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labYear;
    QPushButton *pushButton_2;
    QLabel *labAll;
    QLabel *labAdmint;
    QLineEdit *leAll;
    QLineEdit *leAdmit;
    QLabel *labRate;
    QLineEdit *leRate;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labYear = new QLabel(centralwidget);
        labYear->setObjectName(QString::fromUtf8("labYear"));
        labYear->setGeometry(QRect(70, 70, 54, 12));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 70, 80, 20));
        labAll = new QLabel(centralwidget);
        labAll->setObjectName(QString::fromUtf8("labAll"));
        labAll->setGeometry(QRect(70, 140, 54, 12));
        labAdmint = new QLabel(centralwidget);
        labAdmint->setObjectName(QString::fromUtf8("labAdmint"));
        labAdmint->setGeometry(QRect(70, 200, 54, 12));
        leAll = new QLineEdit(centralwidget);
        leAll->setObjectName(QString::fromUtf8("leAll"));
        leAll->setGeometry(QRect(160, 140, 113, 20));
        leAdmit = new QLineEdit(centralwidget);
        leAdmit->setObjectName(QString::fromUtf8("leAdmit"));
        leAdmit->setGeometry(QRect(160, 200, 113, 20));
        labRate = new QLabel(centralwidget);
        labRate->setObjectName(QString::fromUtf8("labRate"));
        labRate->setGeometry(QRect(340, 200, 54, 12));
        leRate = new QLineEdit(centralwidget);
        leRate->setObjectName(QString::fromUtf8("leRate"));
        leRate->setGeometry(QRect(430, 200, 113, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 70, 72, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labYear->setText(QCoreApplication::translate("MainWindow", "\345\271\264\344\273\275", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        labAll->setText(QCoreApplication::translate("MainWindow", "\351\253\230\350\200\203\344\272\272\346\225\260", nullptr));
        labAdmint->setText(QCoreApplication::translate("MainWindow", "\345\275\225\345\217\226\344\272\272\346\225\260", nullptr));
        labRate->setText(QCoreApplication::translate("MainWindow", "\345\275\225\345\217\226\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
