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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labBlurView;
    QLabel *labGaussianView;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labMedianView;
    QLabel *labBilateralView;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *btnSave;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *rdbAverage;
    QRadioButton *rdbGaussian;
    QRadioButton *rdbMedian;
    QRadioButton *rdbBilateral;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labBlurView = new QLabel(centralwidget);
        labBlurView->setObjectName(QString::fromUtf8("labBlurView"));
        labBlurView->setGeometry(QRect(30, 40, 300, 186));
        labBlurView->setFrameShape(QFrame::Box);
        labBlurView->setFrameShadow(QFrame::Sunken);
        labGaussianView = new QLabel(centralwidget);
        labGaussianView->setObjectName(QString::fromUtf8("labGaussianView"));
        labGaussianView->setGeometry(QRect(350, 40, 300, 186));
        labGaussianView->setFrameShape(QFrame::Box);
        labGaussianView->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 240, 54, 12));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 240, 54, 12));
        labMedianView = new QLabel(centralwidget);
        labMedianView->setObjectName(QString::fromUtf8("labMedianView"));
        labMedianView->setGeometry(QRect(30, 290, 300, 186));
        labMedianView->setFrameShape(QFrame::Box);
        labMedianView->setFrameShadow(QFrame::Sunken);
        labBilateralView = new QLabel(centralwidget);
        labBilateralView->setObjectName(QString::fromUtf8("labBilateralView"));
        labBilateralView->setGeometry(QRect(350, 290, 300, 186));
        labBilateralView->setFrameShape(QFrame::Box);
        labBilateralView->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(170, 490, 54, 12));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(480, 490, 54, 12));
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(680, 230, 80, 20));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(680, 50, 91, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rdbAverage = new QRadioButton(widget);
        rdbAverage->setObjectName(QString::fromUtf8("rdbAverage"));

        verticalLayout->addWidget(rdbAverage);

        rdbGaussian = new QRadioButton(widget);
        rdbGaussian->setObjectName(QString::fromUtf8("rdbGaussian"));

        verticalLayout->addWidget(rdbGaussian);

        rdbMedian = new QRadioButton(widget);
        rdbMedian->setObjectName(QString::fromUtf8("rdbMedian"));

        verticalLayout->addWidget(rdbMedian);

        rdbBilateral = new QRadioButton(widget);
        rdbBilateral->setObjectName(QString::fromUtf8("rdbBilateral"));

        verticalLayout->addWidget(rdbBilateral);

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
        labBlurView->setText(QString());
        labGaussianView->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\235\207\345\200\274\346\273\244\346\263\242", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
        labMedianView->setText(QString());
        labBilateralView->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\217\214\350\276\271\346\273\244\346\263\242", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272...", nullptr));
        rdbAverage->setText(QCoreApplication::translate("MainWindow", "Average", nullptr));
        rdbGaussian->setText(QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        rdbMedian->setText(QCoreApplication::translate("MainWindow", "Median", nullptr));
        rdbBilateral->setText(QCoreApplication::translate("MainWindow", "Bilateral", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
