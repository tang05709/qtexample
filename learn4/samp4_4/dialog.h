#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void createCtrlFrame();
    void createContentFrame();
    void fillColorList(QComboBox *);

private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();

private:
    QFrame *frameCtrl;
    QLabel *labWindow;
    QComboBox *cmbWindow;
    QLabel *labWindowText;
    QComboBox *cmbWindowText;
    QLabel *labButton;
    QComboBox *cmbButton;
    QLabel *labButtonText;
    QComboBox *cmbButtonText;
    QLabel *labBase;
    QComboBox *cmbBase;

    QFrame *frameContent;
    QLabel *labValue;
    QComboBox *cmbValue;
    QLabel *labStr;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *btnOk;
    QPushButton *btnCancel;
};
#endif // DIALOG_H
