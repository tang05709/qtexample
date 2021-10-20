#ifndef INPUTDLG_H
#define INPUTDLG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>

class InputDlg : public QDialog
{
    Q_OBJECT
public:
    InputDlg(QWidget *parent = nullptr);

private:
    QLabel *labName;
    QLabel *labSex;
    QLabel *labAge;
    QLabel *labScore;
    QLabel *labName2;
    QLabel *labSex2;
    QLabel *labAge2;
    QLabel *labScore2;
    QPushButton *btnName;
    QPushButton *btnSex;
    QPushButton *btnAge;
    QPushButton *btnScoure;
    QGridLayout *mainLayout;


private slots:
    void changeName();
    void changeSex();
    void changeAge();
    void changeScore();
};

#endif // INPUTDLG_H
