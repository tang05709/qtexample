#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFrame>
#include "inputdlg.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *btnFile;
    QPushButton *btnColor;
    QLineEdit *leFile;
    QGridLayout *mainLayout;
    QFrame *frameColor;
    QPushButton *btnFont;
    QLineEdit *leFont;
    QPushButton *btnInput;
    InputDlg *inputDlg;
    QPushButton *btnCustomDialog;
    QLabel *label;

private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showCustomDlg();
};
#endif // WIDGET_H
