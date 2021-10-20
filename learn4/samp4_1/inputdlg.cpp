#include "inputdlg.h"
#include <QInputDialog>

InputDlg::InputDlg(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("标准输入对话框实例"));

    labName = new QLabel(tr("姓名："));
    labName2 = new QLabel;
    labName2->setText(tr("唐山"));
    labName2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    btnName = new QPushButton(tr("修改姓名"));

    labSex = new QLabel(tr("性别："));
    labSex2 = new QLabel;
    labSex2->setText(tr("男"));
    labSex2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    btnSex = new QPushButton(tr("修改性别"));

    labAge = new QLabel(tr("年龄："));
    labAge2 = new QLabel;
    labAge2->setText(tr("21"));
    labAge2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    btnAge = new QPushButton(tr("修改年龄"));

    labScore = new QLabel(tr("成绩："));
    labScore2 = new QLabel;
    labScore2->setText(tr("80"));
    labScore2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    btnScoure = new QPushButton(tr("修改成绩"));

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(labName, 0, 0);
    mainLayout->addWidget(labName2, 0, 1);
    mainLayout->addWidget(btnName, 0, 2);
    mainLayout->addWidget(labSex, 1, 0);
    mainLayout->addWidget(labSex2, 1, 1);
    mainLayout->addWidget(btnSex, 1, 2);
    mainLayout->addWidget(labAge, 2, 0);
    mainLayout->addWidget(labAge2, 2, 1);
    mainLayout->addWidget(btnAge, 2, 2);
    mainLayout->addWidget(labScore, 3, 0);
    mainLayout->addWidget(labScore2, 3, 1);
    mainLayout->addWidget(btnScoure, 3, 2);

    connect(btnName, SIGNAL(clicked()), this, SLOT(changeName()));
    connect(btnSex, SIGNAL(clicked()), this, SLOT(changeSex()));
    connect(btnAge, SIGNAL(clicked()), this, SLOT(changeAge()));
    connect(btnScoure, SIGNAL(clicked()), this, SLOT(changeScore()));
}


void InputDlg::changeName()
{
    bool ok = false;
    QString text = QInputDialog::getText(this, tr("标准字符串输入对话框"), tr("请输入姓名"), QLineEdit::Normal, labName2->text(), &ok);
    if (ok && !text.isEmpty()) {
        labName2->setText(text);
    }
}

void InputDlg::changeSex()
{
    QStringList sexItems;
    sexItems << tr("男") << tr("女");
    bool ok = false;
    QString sexItem = QInputDialog::getItem(this, tr("标准条目选择对话框"), tr("请选择性别"), sexItems, 0, false, &ok);
    if (ok && !sexItem.isEmpty()) {
        labSex2->setText(sexItem);
    }
}

void InputDlg::changeAge()
{
    bool ok = false;
    int age = QInputDialog::getInt(this, tr("标准int类型输入对话框"), tr("请输入年龄"), labAge2->text().toInt(&ok), 0, 100, 1, &ok);
    if (ok) {
        labAge2->setText(QString(tr("%1")).arg(age));
    }
}

void InputDlg::changeScore()
{
    bool ok = false;
    double score = QInputDialog::getDouble(this, tr("标准double类型输入对话框"), tr("请输入成绩"), labScore2->text().toDouble(&ok), 0, 100, 1, &ok);
    if (ok) {
        labScore2->setText(QString(tr("%1")).arg(score));
    }
}
