#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
    labEmail = new QLabel(tr("电子邮件："));
    leEmail = new QLineEdit;
    labAddr = new QLabel(tr("联系地址："));
    leAddr = new QLineEdit;
    labCode = new QLabel(tr("邮政编码："));
    leCode = new QLineEdit;
    labMoviTel = new QLabel(tr("移动电话："));
    leMoviTel = new QLineEdit;
    chkMoviTel = new QCheckBox(tr("接收留言"));
    labProTel = new QLabel(tr("办公电话："));
    leProTel = new QLineEdit;

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(labEmail, 0, 0);
    mainLayout->addWidget(leEmail, 0, 1);
    mainLayout->addWidget(labAddr, 1, 0);
    mainLayout->addWidget(leAddr, 1, 1);
    mainLayout->addWidget(labCode, 2, 0);
    mainLayout->addWidget(leCode, 2, 1);
    mainLayout->addWidget(labMoviTel, 3, 0);
    mainLayout->addWidget(leMoviTel, 3, 1);
    mainLayout->addWidget(chkMoviTel, 3, 2);
    mainLayout->addWidget(labProTel, 4, 0);
    mainLayout->addWidget(leProTel, 4, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
