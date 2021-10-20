#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include "showwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);
protected slots:
    void showNewFile();
    void showOpenFile();
    void showPrintText();
    void showPrintImage();
    void showZoomIn();
    void showZoomOut();
    void showRatate90();
    void showRatate180();
    void showRatate270();
    void showMirrorVertical();
    void showMirrorHorizontal();
    void showFontComboBox(QString comboStr);
    void showSizeSpinBox(QString spinValue);
    void showBoldBtn();
    void showItalicBtn();
    void showUnderlineBtn();
    void showColorBtn();
    void showCurrentFormatChanged(const QTextCharFormat &fmt);
    void showList(int);
    void showAlignment(QAction *act);
    void showCursorPositionChanged();
private:
    QMenu *menuFile;
    QMenu *menuZoom;
    QMenu *menuRotate;
    QMenu *menuMirror;
    QImage img;
    QString fileName;
    ShowWidget *showWidget;
    QAction *actOpenFile;
    QAction *actNewFile;
    QAction *actPrintText;
    QAction *actPrintImage;
    QAction *actExit;
    QAction *actCopy;
    QAction *actCut;
    QAction *actPaste;
    QAction *actAbout;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actRotate90;
    QAction *actRotate180;
    QAction *actRotate270;
    QAction *actMirrorVertical;
    QAction *actMirrorHorizontal;
    QAction *actUndo;
    QAction *actRedo;
    QToolBar *toolFile;
    QToolBar *toolZoom;
    QToolBar *toolRotate;
    QToolBar *toolMirror;
    QToolBar *toolDoBar;

    QLabel *labFont;
    QFontComboBox *fontComboBox;
    QLabel *labFont2;
    QComboBox *cmbSize;
    QToolButton *toolBtnBold;
    QToolButton *toolBtnItalic;
    QToolButton *toolBtnUnderline;
    QToolButton *toolBtnColor;
    QToolBar *toolFont;

    QLabel *labList;
    QComboBox *cmbList;
    QActionGroup *actGroup;
    QAction *actLeft;
    QAction *actRight;
    QAction *actCenter;
    QAction *actJustify;
    QToolBar *toolList;

};
#endif // MAINWINDOW_H
