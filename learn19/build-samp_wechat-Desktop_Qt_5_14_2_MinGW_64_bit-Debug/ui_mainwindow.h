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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *menu;
    QLabel *search;
    QPushButton *btnSearch;
    QTableWidget *twgUserList;
    QLabel *labUserBg;
    QLabel *labUser;
    QTextBrowser *browserChatText;
    QLabel *labTool;
    QPushButton *btnTrans;
    QTextEdit *teChat;
    QPushButton *btnSendMsg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(741, 546);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        menu = new QLabel(centralwidget);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(0, 0, 60, 500));
        menu->setFrameShape(QFrame::Box);
        menu->setFrameShadow(QFrame::Sunken);
        menu->setPixmap(QPixmap(QString::fromUtf8(":/images/image/bar.png")));
        menu->setScaledContents(true);
        search = new QLabel(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(60, 0, 250, 65));
        search->setFrameShape(QFrame::Box);
        search->setFrameShadow(QFrame::Sunken);
        search->setPixmap(QPixmap(QString::fromUtf8(":/images/image/search.png")));
        search->setScaledContents(true);
        btnSearch = new QPushButton(centralwidget);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setGeometry(QRect(74, 25, 190, 26));
        btnSearch->setFlat(true);
        twgUserList = new QTableWidget(centralwidget);
        twgUserList->setObjectName(QString::fromUtf8("twgUserList"));
        twgUserList->setGeometry(QRect(60, 65, 250, 435));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(14);
        twgUserList->setFont(font);
        twgUserList->setSelectionMode(QAbstractItemView::SingleSelection);
        twgUserList->setSelectionBehavior(QAbstractItemView::SelectRows);
        twgUserList->setShowGrid(false);
        twgUserList->horizontalHeader()->setVisible(false);
        twgUserList->horizontalHeader()->setDefaultSectionSize(250);
        twgUserList->verticalHeader()->setVisible(false);
        labUserBg = new QLabel(centralwidget);
        labUserBg->setObjectName(QString::fromUtf8("labUserBg"));
        labUserBg->setGeometry(QRect(310, 0, 432, 65));
        labUserBg->setFrameShape(QFrame::Box);
        labUserBg->setFrameShadow(QFrame::Sunken);
        labUserBg->setPixmap(QPixmap(QString::fromUtf8(":/images/image/title.png")));
        labUserBg->setScaledContents(true);
        labUser = new QLabel(centralwidget);
        labUser->setObjectName(QString::fromUtf8("labUser"));
        labUser->setGeometry(QRect(311, 1, 120, 62));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(16);
        labUser->setFont(font1);
        labUser->setAlignment(Qt::AlignCenter);
        browserChatText = new QTextBrowser(centralwidget);
        browserChatText->setObjectName(QString::fromUtf8("browserChatText"));
        browserChatText->setGeometry(QRect(310, 65, 431, 304));
        labTool = new QLabel(centralwidget);
        labTool->setObjectName(QString::fromUtf8("labTool"));
        labTool->setGeometry(QRect(310, 369, 432, 36));
        labTool->setFrameShape(QFrame::Box);
        labTool->setFrameShadow(QFrame::Sunken);
        labTool->setPixmap(QPixmap(QString::fromUtf8(":/images/image/tool.png")));
        labTool->setScaledContents(true);
        btnTrans = new QPushButton(centralwidget);
        btnTrans->setObjectName(QString::fromUtf8("btnTrans"));
        btnTrans->setGeometry(QRect(348, 378, 21, 21));
        btnTrans->setFlat(true);
        teChat = new QTextEdit(centralwidget);
        teChat->setObjectName(QString::fromUtf8("teChat"));
        teChat->setGeometry(QRect(310, 403, 431, 97));
        btnSendMsg = new QPushButton(centralwidget);
        btnSendMsg->setObjectName(QString::fromUtf8("btnSendMsg"));
        btnSendMsg->setGeometry(QRect(665, 476, 75, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(10);
        btnSendMsg->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 741, 22));
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
        menu->setText(QString());
        search->setText(QString());
        btnSearch->setText(QString());
        labUserBg->setText(QString());
        labUser->setText(QString());
        labTool->setText(QString());
        btnTrans->setText(QString());
        btnSendMsg->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
