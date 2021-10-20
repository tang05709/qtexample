#include "dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Extension Dialog"));
    createBaseInfo();
    createDetailInfo();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(wgtBase);
    layout->addWidget(wgtDetail);
    layout->setSpacing(10);
    layout->setSizeConstraint(QLayout::SetFixedSize);
}

Dialog::~Dialog()
{
}

void Dialog::createBaseInfo()
{
    wgtBase = new QWidget;

    QLabel *labName = new QLabel(tr("姓名："));
    QLineEdit *leName = new QLineEdit;

    QLabel *labSex = new QLabel(tr("性别："));
    QComboBox *cmbSex = new QComboBox;
    cmbSex->insertItem(0, tr("女"));
    cmbSex->insertItem(0, tr("男"));

    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(labName, 0, 0);
    leftLayout->addWidget(leName, 0, 1);
    leftLayout->addWidget(labSex, 1, 0);
    leftLayout->addWidget(cmbSex, 1, 1);

    QPushButton *btnOk = new QPushButton(tr("确定"));
    QPushButton *btnDetail = new QPushButton(tr("详细"));

    QDialogButtonBox *btnBox = new QDialogButtonBox(Qt::Vertical);
    btnBox->addButton(btnOk, QDialogButtonBox::ActionRole);
    btnBox->addButton(btnDetail, QDialogButtonBox::ActionRole);

    QHBoxLayout *mainLayout = new QHBoxLayout(wgtBase);
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(btnBox);

    connect(btnDetail, SIGNAL(clicked()), this, SLOT(showDetailInfo()));
}

void Dialog::createDetailInfo()
{
    wgtDetail = new QWidget;

    QLabel *labAge = new QLabel(tr("年龄："));
    QLineEdit *leAge = new QLineEdit;
    leAge->setText(tr("30"));

    QLabel *labDepartment = new QLabel(tr("部门："));
    QComboBox *cmbDepartment = new QComboBox;
    cmbDepartment->addItem(tr("技术部"));
    cmbDepartment->addItem(tr("市场部"));
    cmbDepartment->addItem(tr("行政部"));

    QLabel *labEmail = new QLabel(tr("Email："));
    QLineEdit *leEmail = new QLineEdit;

    QGridLayout *mainLayout = new QGridLayout(wgtDetail);
    mainLayout->addWidget(labAge, 0, 0);
    mainLayout->addWidget(leAge, 0, 1);
    mainLayout->addWidget(labDepartment, 1, 0);
    mainLayout->addWidget(cmbDepartment, 1, 1);
    mainLayout->addWidget(labEmail, 2, 0);
    mainLayout->addWidget(leEmail, 2, 1);
    wgtDetail->hide();
}

void Dialog::showDetailInfo()
{
    if (wgtDetail->isHidden()) {
        wgtDetail->show();
    } else {
        wgtDetail->hide();
    }
}
