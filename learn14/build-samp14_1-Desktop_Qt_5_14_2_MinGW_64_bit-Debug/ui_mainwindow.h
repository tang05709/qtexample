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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QGroupBox *gbExcel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *leExcel;
    QPushButton *btnExcelRead;
    QPushButton *btnExcelWrite;
    QLabel *labExcel;
    QGroupBox *groupBox;
    QWidget *widget1;
    QGridLayout *gridLayout_4;
    QLineEdit *leWord;
    QPushButton *btnWordRead;
    QPushButton *btnWordWrite;
    QLabel *labWord;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gbExcel = new QGroupBox(centralwidget);
        gbExcel->setObjectName(QString::fromUtf8("gbExcel"));
        gbExcel->setGeometry(QRect(40, 30, 321, 141));
        widget = new QWidget(gbExcel);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 40, 281, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leExcel = new QLineEdit(widget);
        leExcel->setObjectName(QString::fromUtf8("leExcel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leExcel->sizePolicy().hasHeightForWidth());
        leExcel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(leExcel, 0, 0, 1, 1);

        btnExcelRead = new QPushButton(widget);
        btnExcelRead->setObjectName(QString::fromUtf8("btnExcelRead"));
        btnExcelRead->setEnabled(false);

        gridLayout->addWidget(btnExcelRead, 0, 1, 1, 1);

        btnExcelWrite = new QPushButton(widget);
        btnExcelWrite->setObjectName(QString::fromUtf8("btnExcelWrite"));

        gridLayout->addWidget(btnExcelWrite, 1, 0, 1, 1);

        labExcel = new QLabel(widget);
        labExcel->setObjectName(QString::fromUtf8("labExcel"));
        labExcel->setFrameShape(QFrame::Panel);

        gridLayout->addWidget(labExcel, 1, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 220, 321, 121));
        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 30, 281, 81));
        gridLayout_4 = new QGridLayout(widget1);
        gridLayout_4->setSpacing(20);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        leWord = new QLineEdit(widget1);
        leWord->setObjectName(QString::fromUtf8("leWord"));
        sizePolicy.setHeightForWidth(leWord->sizePolicy().hasHeightForWidth());
        leWord->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(leWord, 0, 0, 1, 1);

        btnWordRead = new QPushButton(widget1);
        btnWordRead->setObjectName(QString::fromUtf8("btnWordRead"));
        btnWordRead->setEnabled(false);

        gridLayout_4->addWidget(btnWordRead, 0, 1, 1, 1);

        btnWordWrite = new QPushButton(widget1);
        btnWordWrite->setObjectName(QString::fromUtf8("btnWordWrite"));

        gridLayout_4->addWidget(btnWordWrite, 1, 0, 1, 1);

        labWord = new QLabel(widget1);
        labWord->setObjectName(QString::fromUtf8("labWord"));
        labWord->setFrameShape(QFrame::Panel);

        gridLayout_4->addWidget(labWord, 1, 1, 1, 1);

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
        gbExcel->setTitle(QCoreApplication::translate("MainWindow", "Excel\350\257\273\345\206\231", nullptr));
        leExcel->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\210\261\346\234\200\346\226\260\347\232\204Qt5", nullptr));
        btnExcelRead->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        btnExcelWrite->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        labExcel->setText(QCoreApplication::translate("MainWindow", "excel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Word\350\257\273\345\206\231", nullptr));
        leWord->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\210\261\346\234\200\346\226\260\347\232\204Qt5", nullptr));
        btnWordRead->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\207\272", nullptr));
        btnWordWrite->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245", nullptr));
        labWord->setText(QCoreApplication::translate("MainWindow", "word", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
