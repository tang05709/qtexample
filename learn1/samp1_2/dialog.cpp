#include "dialog.h"
#include <QGridLayout>

const static double PI = 3.1416;
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    labRadius = new QLabel(this);
    labRadius->setText(tr("半径"));
    labArea = new QLabel(this);
    labArea->setText(tr("面积"));
    labResult = new QLabel(this);
    labResult->setText("");
    leRadius = new QLineEdit(this);
    btnCount = new QPushButton(this);
    btnCount->setText(tr("计算"));

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(labRadius, 0, 0);
    layout->addWidget(leRadius, 0, 1);
    layout->addWidget(labArea, 0, 2);
    layout->addWidget(labResult, 0, 3);
    layout->addWidget(btnCount, 1, 3);
    layout->setMargin(30);
    setLayout(layout);

    connect(btnCount, SIGNAL(clicked()), this, SLOT(showArea()));
    connect(leRadius, SIGNAL(textChanged(QString)), this, SLOT(showArea()));
}

Dialog::~Dialog()
{
}

void Dialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = leRadius->text();
    int valueInt = valueStr.toUInt(&ok);
    if (ok) {
        double area = valueInt * valueInt * PI;
        labResult->setText(tempStr.setNum(area));
    }
}
