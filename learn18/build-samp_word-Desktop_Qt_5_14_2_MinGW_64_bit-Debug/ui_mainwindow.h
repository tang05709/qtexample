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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actNew;
    QAction *actOpen;
    QAction *actSave;
    QAction *actSaveAs;
    QAction *actPrint;
    QAction *actPrintPreview;
    QAction *actExit;
    QAction *actUndo;
    QAction *actRedo;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actBold;
    QAction *actItalic;
    QAction *actUnderline;
    QAction *actLeftAlign;
    QAction *actRightAlign;
    QAction *actCenterAlign;
    QAction *actJustify;
    QAction *actColor;
    QAction *actClose;
    QAction *actCloseAll;
    QAction *actTile;
    QAction *actCascade;
    QAction *actNext;
    QAction *actPrevious;
    QAction *actAbout;
    QAction *actAboutQt;
    QWidget *centralwidget;
    QComboBox *cmbFont;
    QComboBox *cmbFontSize;
    QComboBox *cmbListStyle;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_D;
    QMenu *menu;
    QMenu *menu_W;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actNew = new QAction(MainWindow);
        actNew->setObjectName(QString::fromUtf8("actNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actNew->setIcon(icon);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QString::fromUtf8("actOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon1);
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon2);
        actSaveAs = new QAction(MainWindow);
        actSaveAs->setObjectName(QString::fromUtf8("actSaveAs"));
        actPrint = new QAction(MainWindow);
        actPrint->setObjectName(QString::fromUtf8("actPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/fileprint.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPrint->setIcon(icon3);
        actPrintPreview = new QAction(MainWindow);
        actPrintPreview->setObjectName(QString::fromUtf8("actPrintPreview"));
        actExit = new QAction(MainWindow);
        actExit->setObjectName(QString::fromUtf8("actExit"));
        actUndo = new QAction(MainWindow);
        actUndo->setObjectName(QString::fromUtf8("actUndo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/editundo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actUndo->setIcon(icon4);
        actRedo = new QAction(MainWindow);
        actRedo->setObjectName(QString::fromUtf8("actRedo"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/editredo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actRedo->setIcon(icon5);
        actCut = new QAction(MainWindow);
        actCut->setObjectName(QString::fromUtf8("actCut"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/editcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon6);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName(QString::fromUtf8("actCopy"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon7);
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName(QString::fromUtf8("actPaste"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/editpaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon8);
        actBold = new QAction(MainWindow);
        actBold->setObjectName(QString::fromUtf8("actBold"));
        actBold->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actBold->setIcon(icon9);
        actItalic = new QAction(MainWindow);
        actItalic->setObjectName(QString::fromUtf8("actItalic"));
        actItalic->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actItalic->setIcon(icon10);
        actUnderline = new QAction(MainWindow);
        actUnderline->setObjectName(QString::fromUtf8("actUnderline"));
        actUnderline->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/images/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actUnderline->setIcon(icon11);
        actLeftAlign = new QAction(MainWindow);
        actLeftAlign->setObjectName(QString::fromUtf8("actLeftAlign"));
        actLeftAlign->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/images/textleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLeftAlign->setIcon(icon12);
        actRightAlign = new QAction(MainWindow);
        actRightAlign->setObjectName(QString::fromUtf8("actRightAlign"));
        actRightAlign->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/images/textright.png"), QSize(), QIcon::Normal, QIcon::Off);
        actRightAlign->setIcon(icon13);
        actCenterAlign = new QAction(MainWindow);
        actCenterAlign->setObjectName(QString::fromUtf8("actCenterAlign"));
        actCenterAlign->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/images/textcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCenterAlign->setIcon(icon14);
        actJustify = new QAction(MainWindow);
        actJustify->setObjectName(QString::fromUtf8("actJustify"));
        actJustify->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/images/textjustify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actJustify->setIcon(icon15);
        actColor = new QAction(MainWindow);
        actColor->setObjectName(QString::fromUtf8("actColor"));
        actColor->setCheckable(true);
        actClose = new QAction(MainWindow);
        actClose->setObjectName(QString::fromUtf8("actClose"));
        actCloseAll = new QAction(MainWindow);
        actCloseAll->setObjectName(QString::fromUtf8("actCloseAll"));
        actTile = new QAction(MainWindow);
        actTile->setObjectName(QString::fromUtf8("actTile"));
        actCascade = new QAction(MainWindow);
        actCascade->setObjectName(QString::fromUtf8("actCascade"));
        actNext = new QAction(MainWindow);
        actNext->setObjectName(QString::fromUtf8("actNext"));
        actPrevious = new QAction(MainWindow);
        actPrevious->setObjectName(QString::fromUtf8("actPrevious"));
        actAbout = new QAction(MainWindow);
        actAbout->setObjectName(QString::fromUtf8("actAbout"));
        actAboutQt = new QAction(MainWindow);
        actAboutQt->setObjectName(QString::fromUtf8("actAboutQt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cmbFont = new QComboBox(centralwidget);
        cmbFont->setObjectName(QString::fromUtf8("cmbFont"));
        cmbFont->setGeometry(QRect(100, 0, 191, 22));
        cmbFontSize = new QComboBox(centralwidget);
        cmbFontSize->setObjectName(QString::fromUtf8("cmbFontSize"));
        cmbFontSize->setGeometry(QRect(290, 0, 51, 22));
        cmbListStyle = new QComboBox(centralwidget);
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->addItem(QString());
        cmbListStyle->setObjectName(QString::fromUtf8("cmbListStyle"));
        cmbListStyle->setGeometry(QRect(0, 0, 101, 22));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(0, 30, 801, 461));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_O = new QMenu(menubar);
        menu_O->setObjectName(QString::fromUtf8("menu_O"));
        menu_D = new QMenu(menu_O);
        menu_D->setObjectName(QString::fromUtf8("menu_D"));
        menu = new QMenu(menu_O);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_W = new QMenu(menubar);
        menu_W->setObjectName(QString::fromUtf8("menu_W"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu_W->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(actNew);
        menu_F->addAction(actOpen);
        menu_F->addSeparator();
        menu_F->addAction(actSave);
        menu_F->addAction(actSaveAs);
        menu_F->addSeparator();
        menu_F->addAction(actPrint);
        menu_F->addAction(actPrintPreview);
        menu_F->addSeparator();
        menu_F->addAction(actExit);
        menu_E->addAction(actUndo);
        menu_E->addAction(actRedo);
        menu_E->addSeparator();
        menu_E->addAction(actCut);
        menu_E->addAction(actCopy);
        menu_E->addAction(actPaste);
        menu_O->addAction(menu_D->menuAction());
        menu_O->addSeparator();
        menu_O->addAction(menu->menuAction());
        menu_O->addSeparator();
        menu_O->addAction(actColor);
        menu_D->addAction(actBold);
        menu_D->addAction(actItalic);
        menu_D->addAction(actUnderline);
        menu->addAction(actLeftAlign);
        menu->addAction(actCenterAlign);
        menu->addAction(actRightAlign);
        menu->addAction(actJustify);
        menu_W->addAction(actClose);
        menu_W->addAction(actCloseAll);
        menu_W->addSeparator();
        menu_W->addAction(actTile);
        menu_W->addAction(actCascade);
        menu_W->addSeparator();
        menu_W->addAction(actNext);
        menu_W->addAction(actPrevious);
        menu_H->addAction(actAbout);
        menu_H->addAction(actAboutQt);
        toolBar->addAction(actNew);
        toolBar->addAction(actOpen);
        toolBar->addAction(actSave);
        toolBar->addAction(actPrint);
        toolBar->addSeparator();
        toolBar->addAction(actUndo);
        toolBar->addAction(actRedo);
        toolBar->addSeparator();
        toolBar->addAction(actCut);
        toolBar->addAction(actCopy);
        toolBar->addAction(actPaste);
        toolBar->addSeparator();
        toolBar->addAction(actBold);
        toolBar->addAction(actItalic);
        toolBar->addAction(actUnderline);
        toolBar->addSeparator();
        toolBar->addAction(actLeftAlign);
        toolBar->addAction(actCenterAlign);
        toolBar->addAction(actRightAlign);
        toolBar->addAction(actJustify);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
#if QT_CONFIG(tooltip)
        actNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actNew->setStatusTip(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\344\270\200\344\270\252\346\226\260\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
#if QT_CONFIG(tooltip)
        actOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actOpen->setStatusTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\267\262\345\255\230\345\234\250\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#if QT_CONFIG(tooltip)
        actSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actSave->setStatusTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actSaveAs->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)...", nullptr));
#if QT_CONFIG(tooltip)
        actSaveAs->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actSaveAs->setStatusTip(QCoreApplication::translate("MainWindow", "\344\273\245\344\270\200\344\270\252\346\226\260\345\220\215\345\255\227\344\277\235\345\255\230\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
        actPrint->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260(&P)...", nullptr));
#if QT_CONFIG(tooltip)
        actPrint->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actPrint->setStatusTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\350\276\223\345\207\272\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actPrint->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actPrintPreview->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        actPrintPreview->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actPrintPreview->setStatusTip(QCoreApplication::translate("MainWindow", "\351\242\204\350\247\210\346\211\223\345\215\260\346\225\210\346\236\234", nullptr));
#endif // QT_CONFIG(statustip)
        actExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", nullptr));
#if QT_CONFIG(tooltip)
        actExit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actExit->setStatusTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\345\272\224\347\224\250\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(statustip)
        actUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200(&U)", nullptr));
#if QT_CONFIG(tooltip)
        actUndo->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actUndo->setStatusTip(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200\345\275\223\345\211\215\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actRedo->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232(&R)", nullptr));
#if QT_CONFIG(tooltip)
        actRedo->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actRedo->setStatusTip(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215\344\271\213\345\211\215\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", nullptr));
#if QT_CONFIG(tooltip)
        actCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actCut->setStatusTip(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\346\241\243\344\270\255\345\211\252\345\210\207\346\211\200\351\200\211\345\206\205\345\256\271\345\271\266\345\260\206\345\205\266\346\224\276\345\205\245\345\211\252\350\264\264\346\235\277", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", nullptr));
#if QT_CONFIG(tooltip)
        actCopy->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actCopy->setStatusTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266\346\211\200\351\200\211\345\206\205\345\256\271\345\271\266\345\260\206\345\205\266\346\224\276\345\205\245\345\211\252\350\264\264\346\235\277", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", nullptr));
#if QT_CONFIG(tooltip)
        actPaste->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actPaste->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\345\211\252\350\264\264\346\235\277\347\232\204\345\206\205\345\256\271\347\262\230\350\264\264\345\210\260\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actBold->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227(&B)", nullptr));
#if QT_CONFIG(tooltip)
        actBold->setToolTip(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actBold->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actBold->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actItalic->setText(QCoreApplication::translate("MainWindow", "\345\200\276\346\226\234(&I)", nullptr));
#if QT_CONFIG(tooltip)
        actItalic->setToolTip(QCoreApplication::translate("MainWindow", "\345\200\276\346\226\234", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actItalic->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\347\224\250\346\226\234\344\275\223\350\241\250\347\244\272", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actItalic->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actUnderline->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277(&U)", nullptr));
#if QT_CONFIG(tooltip)
        actUnderline->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actUnderline->setStatusTip(QCoreApplication::translate("MainWindow", "\344\270\272\346\211\200\351\200\211\346\226\207\345\255\227\346\267\273\345\212\240\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actUnderline->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actLeftAlign->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220(&L)", nullptr));
#if QT_CONFIG(tooltip)
        actLeftAlign->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actLeftAlign->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\226\207\345\255\227\345\267\246\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actLeftAlign->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actRightAlign->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220(&R)", nullptr));
#if QT_CONFIG(tooltip)
        actRightAlign->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actRightAlign->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\226\207\345\255\227\345\217\263\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actRightAlign->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actCenterAlign->setText(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255\345\257\271\351\275\220(&E)", nullptr));
#if QT_CONFIG(tooltip)
        actCenterAlign->setToolTip(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actCenterAlign->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\226\207\345\255\227\345\261\205\344\270\255\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actCenterAlign->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actJustify->setText(QCoreApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220(&J)", nullptr));
#if QT_CONFIG(tooltip)
        actJustify->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actJustify->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\226\207\345\255\227\345\267\246\345\217\263\344\270\244\347\253\257\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actJustify->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+J", nullptr));
#endif // QT_CONFIG(shortcut)
        actColor->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262(&C)...", nullptr));
#if QT_CONFIG(tooltip)
        actColor->setToolTip(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actColor->setStatusTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(statustip)
        actClose->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255(&O)", nullptr));
#if QT_CONFIG(tooltip)
        actClose->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actClose->setStatusTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\264\273\345\212\250\346\226\207\346\241\243\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        actCloseAll->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211(&A)", nullptr));
#if QT_CONFIG(tooltip)
        actCloseAll->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actCloseAll->setStatusTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        actTile->setText(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272(&T)", nullptr));
#if QT_CONFIG(tooltip)
        actTile->setToolTip(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actTile->setStatusTip(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        actCascade->setText(QCoreApplication::translate("MainWindow", "\345\261\202\345\217\240(&C)", nullptr));
#if QT_CONFIG(tooltip)
        actCascade->setToolTip(QCoreApplication::translate("MainWindow", "\345\261\202\345\217\240", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actCascade->setStatusTip(QCoreApplication::translate("MainWindow", "\345\261\202\345\217\240\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        actNext->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(&X)", nullptr));
#if QT_CONFIG(tooltip)
        actNext->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actNext->setStatusTip(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\204\246\347\202\271\345\210\260\344\270\213\344\270\200\344\270\252\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        actPrevious->setText(QCoreApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252(&V)", nullptr));
#if QT_CONFIG(tooltip)
        actPrevious->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actPrevious->setStatusTip(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\204\246\347\202\271\345\210\260\345\211\215\344\270\200\344\270\252\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        actAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", nullptr));
#if QT_CONFIG(tooltip)
        actAbout->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actAbout->setStatusTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", nullptr));
#endif // QT_CONFIG(statustip)
        actAboutQt->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216QT(&Q)", nullptr));
#if QT_CONFIG(tooltip)
        actAboutQt->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216QT", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actAboutQt->setStatusTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216QT", nullptr));
#endif // QT_CONFIG(statustip)
        cmbListStyle->setItemText(0, QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206", nullptr));
        cmbListStyle->setItemText(1, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\217)", nullptr));
        cmbListStyle->setItemText(2, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\213)", nullptr));
        cmbListStyle->setItemText(3, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\206)", nullptr));
        cmbListStyle->setItemText(4, QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267(1.2.3)", nullptr));
        cmbListStyle->setItemText(5, QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267(a,b,c)", nullptr));
        cmbListStyle->setItemText(6, QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267(A,B,C)", nullptr));
        cmbListStyle->setItemText(7, QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267(\342\205\260,\342\205\261,\342\205\262)", nullptr));
        cmbListStyle->setItemText(8, QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267(\342\205\240,\342\205\241,\342\205\242)", nullptr));

        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", nullptr));
        menu_O->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217(O)", nullptr));
        menu_D->setTitle(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223(&D)", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\256\265\350\220\275", nullptr));
        menu_W->setTitle(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243(W)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
