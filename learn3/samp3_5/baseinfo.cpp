#include "baseinfo.h"

BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
{
    // left
    labUserName = new QLabel(tr("用户名："));
    leUserName = new QLineEdit;
    labName = new QLabel(tr("姓名："));
    leName = new QLineEdit;
    labSex = new QLabel(tr("性别："));
    cmbSex = new QComboBox;
    cmbSex->addItem(tr("女"));
    cmbSex->addItem(tr("男"));
    labDepartment = new QLabel(tr("部门："));
    teDepartment = new QTextEdit;
    labAge = new QLabel(tr("年龄："));
    leAge = new QLineEdit;
    labOther = new QLabel(tr("备注："));
    labOther->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    leftLayout = new QGridLayout();
    leftLayout->addWidget(labUserName, 0, 0);
    leftLayout->addWidget(leUserName, 0, 1);
    leftLayout->addWidget(labName, 1, 0);
    leftLayout->addWidget(leName, 1, 1);
    leftLayout->addWidget(labSex, 2, 0);
    leftLayout->addWidget(cmbSex, 2, 1);
    leftLayout->addWidget(labDepartment, 3, 0);
    leftLayout->addWidget(teDepartment, 3, 1);
    leftLayout->addWidget(labAge, 4, 0);
    leftLayout->addWidget(leAge, 4, 1);
    leftLayout->addWidget(labOther, 5, 0, 1, 2);
    leftLayout->setColumnStretch(0, 1);
    leftLayout->setColumnStretch(1, 3);

    // right
    labHead = new QLabel(tr("头像："));
    labHeadIcon = new QLabel;
    labHeadIcon->resize(50, 50);
    QPixmap icon(":/images/avatar.jpg");
    QPixmap avatar = icon.scaled(labHeadIcon->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    labHeadIcon->setPixmap(avatar);
    btnUpdateHead = new QPushButton(tr("更新"));
    // right top
    topRightLayout = new QHBoxLayout();
    topRightLayout->setSpacing(20);
    topRightLayout->addWidget(labHead);
    topRightLayout->addWidget(labHeadIcon);
    topRightLayout->addWidget(btnUpdateHead);
    labIntroduction = new QLabel(tr("个人说明："));
    teIntroduction = new QTextEdit;
    // right bottom
    rightLayout = new QVBoxLayout();
    rightLayout->setMargin(10);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(labIntroduction);
    rightLayout->addWidget(teIntroduction);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
