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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *commodityPage;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *newCommodity;
    QComboBox *cmbNewCategory;
    QLabel *labNewCategory;
    QLabel *labNewName;
    QLineEdit *leNewName;
    QLabel *labNewInPrice;
    QLineEdit *leNewInPrice;
    QLabel *labNewPriceFlag1;
    QLabel *labNewOutPrice;
    QLineEdit *leNewOutPrice;
    QLabel *labNewPriceFlag2;
    QLabel *labNewNumber;
    QSpinBox *spbNewAmount;
    QLabel *labNewPicture;
    QPushButton *btnAdd;
    QPushButton *btnClear;
    QLabel *labNewPixmap;
    QPushButton *btnUpload;
    QTableView *tableView;
    QWidget *orderCommdity;
    QLabel *labPreCategory;
    QComboBox *cmbPreCategory;
    QLabel *labPreName;
    QComboBox *cmbPreName;
    QLabel *labPreSinglePrice;
    QLabel *labPreSinglePriceNum;
    QLabel *labPrePriceFlag1;
    QLabel *labPreAmount;
    QLabel *labPreAmountNum;
    QLabel *labPreAmountFlag;
    QLabel *labPreNumber;
    QSpinBox *spbPreNumber;
    QLabel *labPreTotalPrice;
    QLabel *labPreTotalPriceNum;
    QLabel *labPriceFlag2_2;
    QLabel *labPrePixmap;
    QPushButton *btnSell;
    QPushButton *btnOrder;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 20, 781, 410));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        commodityPage = new QWidget();
        commodityPage->setObjectName(QString::fromUtf8("commodityPage"));
        label = new QLabel(commodityPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 781, 31));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        toolBox = new QToolBox(commodityPage);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(0, 30, 781, 381));
        toolBox->setFrameShape(QFrame::WinPanel);
        newCommodity = new QWidget();
        newCommodity->setObjectName(QString::fromUtf8("newCommodity"));
        newCommodity->setGeometry(QRect(0, 0, 777, 325));
        cmbNewCategory = new QComboBox(newCommodity);
        cmbNewCategory->setObjectName(QString::fromUtf8("cmbNewCategory"));
        cmbNewCategory->setGeometry(QRect(70, 20, 72, 22));
        labNewCategory = new QLabel(newCommodity);
        labNewCategory->setObjectName(QString::fromUtf8("labNewCategory"));
        labNewCategory->setGeometry(QRect(30, 20, 41, 16));
        labNewName = new QLabel(newCommodity);
        labNewName->setObjectName(QString::fromUtf8("labNewName"));
        labNewName->setGeometry(QRect(30, 50, 41, 16));
        leNewName = new QLineEdit(newCommodity);
        leNewName->setObjectName(QString::fromUtf8("leNewName"));
        leNewName->setGeometry(QRect(70, 50, 211, 20));
        labNewInPrice = new QLabel(newCommodity);
        labNewInPrice->setObjectName(QString::fromUtf8("labNewInPrice"));
        labNewInPrice->setGeometry(QRect(30, 80, 41, 16));
        leNewInPrice = new QLineEdit(newCommodity);
        leNewInPrice->setObjectName(QString::fromUtf8("leNewInPrice"));
        leNewInPrice->setGeometry(QRect(70, 80, 61, 20));
        labNewPriceFlag1 = new QLabel(newCommodity);
        labNewPriceFlag1->setObjectName(QString::fromUtf8("labNewPriceFlag1"));
        labNewPriceFlag1->setGeometry(QRect(140, 80, 21, 16));
        labNewOutPrice = new QLabel(newCommodity);
        labNewOutPrice->setObjectName(QString::fromUtf8("labNewOutPrice"));
        labNewOutPrice->setGeometry(QRect(170, 80, 41, 16));
        leNewOutPrice = new QLineEdit(newCommodity);
        leNewOutPrice->setObjectName(QString::fromUtf8("leNewOutPrice"));
        leNewOutPrice->setGeometry(QRect(210, 80, 51, 20));
        labNewPriceFlag2 = new QLabel(newCommodity);
        labNewPriceFlag2->setObjectName(QString::fromUtf8("labNewPriceFlag2"));
        labNewPriceFlag2->setGeometry(QRect(270, 80, 21, 16));
        labNewNumber = new QLabel(newCommodity);
        labNewNumber->setObjectName(QString::fromUtf8("labNewNumber"));
        labNewNumber->setGeometry(QRect(30, 110, 41, 16));
        spbNewAmount = new QSpinBox(newCommodity);
        spbNewAmount->setObjectName(QString::fromUtf8("spbNewAmount"));
        spbNewAmount->setGeometry(QRect(70, 110, 81, 22));
        spbNewAmount->setAlignment(Qt::AlignCenter);
        spbNewAmount->setValue(1);
        labNewPicture = new QLabel(newCommodity);
        labNewPicture->setObjectName(QString::fromUtf8("labNewPicture"));
        labNewPicture->setGeometry(QRect(30, 150, 54, 12));
        btnAdd = new QPushButton(newCommodity);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(30, 190, 80, 20));
        btnClear = new QPushButton(newCommodity);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(30, 230, 80, 20));
        labNewPixmap = new QLabel(newCommodity);
        labNewPixmap->setObjectName(QString::fromUtf8("labNewPixmap"));
        labNewPixmap->setGeometry(QRect(130, 150, 151, 151));
        labNewPixmap->setFrameShape(QFrame::Box);
        labNewPixmap->setFrameShadow(QFrame::Sunken);
        labNewPixmap->setScaledContents(true);
        btnUpload = new QPushButton(newCommodity);
        btnUpload->setObjectName(QString::fromUtf8("btnUpload"));
        btnUpload->setGeometry(QRect(200, 130, 80, 20));
        tableView = new QTableView(newCommodity);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(320, 20, 401, 291));
        tableView->horizontalHeader()->setMinimumSectionSize(25);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);
        toolBox->addItem(newCommodity, QString::fromUtf8("\346\226\260\345\223\201\345\205\245\345\272\223"));
        orderCommdity = new QWidget();
        orderCommdity->setObjectName(QString::fromUtf8("orderCommdity"));
        orderCommdity->setGeometry(QRect(0, 0, 777, 325));
        labPreCategory = new QLabel(orderCommdity);
        labPreCategory->setObjectName(QString::fromUtf8("labPreCategory"));
        labPreCategory->setGeometry(QRect(10, 20, 41, 16));
        cmbPreCategory = new QComboBox(orderCommdity);
        cmbPreCategory->setObjectName(QString::fromUtf8("cmbPreCategory"));
        cmbPreCategory->setGeometry(QRect(50, 20, 72, 22));
        labPreName = new QLabel(orderCommdity);
        labPreName->setObjectName(QString::fromUtf8("labPreName"));
        labPreName->setGeometry(QRect(10, 50, 41, 16));
        cmbPreName = new QComboBox(orderCommdity);
        cmbPreName->setObjectName(QString::fromUtf8("cmbPreName"));
        cmbPreName->setGeometry(QRect(50, 50, 211, 22));
        labPreSinglePrice = new QLabel(orderCommdity);
        labPreSinglePrice->setObjectName(QString::fromUtf8("labPreSinglePrice"));
        labPreSinglePrice->setGeometry(QRect(10, 90, 41, 16));
        labPreSinglePriceNum = new QLabel(orderCommdity);
        labPreSinglePriceNum->setObjectName(QString::fromUtf8("labPreSinglePriceNum"));
        labPreSinglePriceNum->setGeometry(QRect(50, 90, 54, 16));
        labPreSinglePriceNum->setFrameShape(QFrame::Box);
        labPreSinglePriceNum->setFrameShadow(QFrame::Sunken);
        labPrePriceFlag1 = new QLabel(orderCommdity);
        labPrePriceFlag1->setObjectName(QString::fromUtf8("labPrePriceFlag1"));
        labPrePriceFlag1->setGeometry(QRect(120, 90, 21, 16));
        labPreAmount = new QLabel(orderCommdity);
        labPreAmount->setObjectName(QString::fromUtf8("labPreAmount"));
        labPreAmount->setGeometry(QRect(150, 90, 41, 16));
        labPreAmountNum = new QLabel(orderCommdity);
        labPreAmountNum->setObjectName(QString::fromUtf8("labPreAmountNum"));
        labPreAmountNum->setGeometry(QRect(190, 90, 51, 16));
        labPreAmountNum->setFrameShape(QFrame::Box);
        labPreAmountNum->setFrameShadow(QFrame::Sunken);
        labPreAmountFlag = new QLabel(orderCommdity);
        labPreAmountFlag->setObjectName(QString::fromUtf8("labPreAmountFlag"));
        labPreAmountFlag->setGeometry(QRect(250, 90, 21, 16));
        labPreNumber = new QLabel(orderCommdity);
        labPreNumber->setObjectName(QString::fromUtf8("labPreNumber"));
        labPreNumber->setGeometry(QRect(10, 120, 41, 16));
        spbPreNumber = new QSpinBox(orderCommdity);
        spbPreNumber->setObjectName(QString::fromUtf8("spbPreNumber"));
        spbPreNumber->setGeometry(QRect(50, 120, 71, 22));
        spbPreNumber->setAlignment(Qt::AlignCenter);
        spbPreNumber->setValue(1);
        labPreTotalPrice = new QLabel(orderCommdity);
        labPreTotalPrice->setObjectName(QString::fromUtf8("labPreTotalPrice"));
        labPreTotalPrice->setGeometry(QRect(150, 120, 41, 16));
        labPreTotalPriceNum = new QLabel(orderCommdity);
        labPreTotalPriceNum->setObjectName(QString::fromUtf8("labPreTotalPriceNum"));
        labPreTotalPriceNum->setGeometry(QRect(190, 120, 51, 16));
        labPreTotalPriceNum->setFrameShape(QFrame::Box);
        labPreTotalPriceNum->setFrameShadow(QFrame::Sunken);
        labPriceFlag2_2 = new QLabel(orderCommdity);
        labPriceFlag2_2->setObjectName(QString::fromUtf8("labPriceFlag2_2"));
        labPriceFlag2_2->setGeometry(QRect(250, 120, 21, 16));
        labPrePixmap = new QLabel(orderCommdity);
        labPrePixmap->setObjectName(QString::fromUtf8("labPrePixmap"));
        labPrePixmap->setGeometry(QRect(10, 160, 151, 151));
        labPrePixmap->setFrameShape(QFrame::Box);
        labPrePixmap->setFrameShadow(QFrame::Sunken);
        labPrePixmap->setScaledContents(true);
        btnSell = new QPushButton(orderCommdity);
        btnSell->setObjectName(QString::fromUtf8("btnSell"));
        btnSell->setGeometry(QRect(180, 190, 80, 20));
        btnOrder = new QPushButton(orderCommdity);
        btnOrder->setObjectName(QString::fromUtf8("btnOrder"));
        btnOrder->setEnabled(false);
        btnOrder->setGeometry(QRect(180, 220, 80, 20));
        listWidget = new QListWidget(orderCommdity);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(300, 20, 441, 311));
        toolBox->addItem(orderCommdity, QString::fromUtf8("\351\242\204\345\224\256\350\256\242\345\215\225"));
        stackedWidget->addWidget(commodityPage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        labNewCategory->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\210\253\357\274\232", nullptr));
        labNewName->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260\357\274\232", nullptr));
        labNewInPrice->setText(QCoreApplication::translate("MainWindow", "\350\277\233\344\273\267\357\274\232", nullptr));
        labNewPriceFlag1->setText(QCoreApplication::translate("MainWindow", "\357\277\245", nullptr));
        labNewOutPrice->setText(QCoreApplication::translate("MainWindow", "\345\224\256\344\273\267\357\274\232", nullptr));
        labNewPriceFlag2->setText(QCoreApplication::translate("MainWindow", "\357\277\245", nullptr));
        labNewNumber->setText(QCoreApplication::translate("MainWindow", "\346\225\260\351\207\217\357\274\232", nullptr));
        labNewPicture->setText(QCoreApplication::translate("MainWindow", "\345\225\206\345\223\201\345\233\276\347\211\207\357\274\232", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\345\205\245\345\272\223", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\344\273\223", nullptr));
        labNewPixmap->setText(QString());
        btnUpload->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\274\240...", nullptr));
        toolBox->setItemText(toolBox->indexOf(newCommodity), QCoreApplication::translate("MainWindow", "\346\226\260\345\223\201\345\205\245\345\272\223", nullptr));
        labPreCategory->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\210\253\357\274\232", nullptr));
        labPreName->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260\357\274\232", nullptr));
        labPreSinglePrice->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\273\267\357\274\232", nullptr));
        labPreSinglePriceNum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labPrePriceFlag1->setText(QCoreApplication::translate("MainWindow", "\357\277\245", nullptr));
        labPreAmount->setText(QCoreApplication::translate("MainWindow", "\345\272\223\345\255\230\357\274\232", nullptr));
        labPreAmountNum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labPreAmountFlag->setText(QCoreApplication::translate("MainWindow", "\344\273\266", nullptr));
        labPreNumber->setText(QCoreApplication::translate("MainWindow", "\346\225\260\351\207\217\357\274\232", nullptr));
        labPreTotalPrice->setText(QCoreApplication::translate("MainWindow", "\346\200\273\344\273\267\357\274\232", nullptr));
        labPreTotalPriceNum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labPriceFlag2_2->setText(QCoreApplication::translate("MainWindow", "\357\277\245", nullptr));
        labPrePixmap->setText(QString());
        btnSell->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\224\256", nullptr));
        btnOrder->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\215\225", nullptr));
        toolBox->setItemText(toolBox->indexOf(orderCommdity), QCoreApplication::translate("MainWindow", "\351\242\204\345\224\256\350\256\242\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
