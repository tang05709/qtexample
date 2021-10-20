#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = nullptr);

signals:

private:
    // left
    QLabel *labUserName;
    QLabel *labName;
    QLabel *labSex;
    QLabel *labDepartment;
    QLabel *labAge;
    QLabel *labOther;
    QLineEdit *leUserName;
    QLineEdit *leName;
    QComboBox *cmbSex;
    QTextEdit *teDepartment;
    QLineEdit *leAge;
    QGridLayout *leftLayout;

    // right
    QLabel *labHead;
    QLabel *labHeadIcon;
    QPushButton *btnUpdateHead;
    QHBoxLayout *topRightLayout;
    QLabel *labIntroduction;
    QTextEdit *teIntroduction;
    QVBoxLayout *rightLayout;


};

#endif // BASEINFO_H
