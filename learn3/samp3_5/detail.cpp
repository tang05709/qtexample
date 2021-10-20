#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    labNational = new QLabel(tr("国家/地址："));
    cmbNational = new QComboBox;
    cmbNational->insertItem(0, tr("中国"));
    cmbNational->insertItem(1, tr("美国"));
    cmbNational->insertItem(2, tr("英国"));
    labProvince = new QLabel(tr("省份："));
    cmbProvince = new QComboBox;
    cmbProvince->insertItem(0, tr("江苏省"));
    cmbProvince->insertItem(1, tr("山东省"));
    cmbProvince->insertItem(2, tr("浙江省"));
    labCity = new QLabel(tr("城市："));
    leCity = new QLineEdit;
    labIntroduct = new QLabel(tr("个人说明："));
    teIntroduct = new QTextEdit;

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(labNational, 0, 0);
    mainLayout->addWidget(cmbNational, 0, 1);
    mainLayout->addWidget(labProvince, 1, 0);
    mainLayout->addWidget(cmbProvince, 1, 1);
    mainLayout->addWidget(labCity, 2, 0);
    mainLayout->addWidget(leCity, 2, 1);
    mainLayout->addWidget(labIntroduct, 3, 0);
    mainLayout->addWidget(teIntroduct, 3, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
