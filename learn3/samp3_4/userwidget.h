#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


class UserWidget : public QWidget
{
    Q_OBJECT

public:
    UserWidget(QWidget *parent = nullptr);
    ~UserWidget();

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

    // bottom
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QHBoxLayout *bottomLayout;
};
#endif // USERWIDGET_H
