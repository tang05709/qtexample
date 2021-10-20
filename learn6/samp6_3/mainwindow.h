#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawwidget.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QToolButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBar();

public slots:
    void showStyle();
    void showColor();

private:
    DrawWidget *drawWidget;
    QLabel *labStyle;
    QComboBox *cmbStyle;
    QLabel *labWidth;
    QSpinBox *spbWidth;
    QToolButton *toolBtnColor;
    QToolButton *toolBtnClear;
};
#endif // MAINWINDOW_H
