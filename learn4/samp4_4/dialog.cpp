#include "dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(frameCtrl);
    mainLayout->addWidget(frameContent);
}

Dialog::~Dialog()
{
}

void Dialog::createCtrlFrame()
{
    frameCtrl = new QFrame;

    labWindow = new QLabel(tr("QPalette::Window:"));
    cmbWindow = new QComboBox;
    fillColorList(cmbWindow);
    connect(cmbWindow, SIGNAL(activated(int)), this, SLOT(showWindow()));

    labWindowText = new QLabel(tr("QPalette::WindowText:"));
    cmbWindowText = new QComboBox;
    fillColorList(cmbWindowText);
    connect(cmbWindowText, SIGNAL(activated(int)), this, SLOT(showWindowText()));

    labButton = new QLabel(tr("QPalette::Button:"));
    cmbButton = new QComboBox;
    fillColorList(cmbButton);
    connect(cmbButton, SIGNAL(activated(int)), this, SLOT(showButton()));

    labButtonText = new QLabel(tr("QPalette::ButtonText:"));
    cmbButtonText = new QComboBox;
    fillColorList(cmbButtonText);
    connect(cmbButtonText, SIGNAL(activated(int)), this, SLOT(showButtonText()));

    labBase = new QLabel(tr("QPalette::Base:"));
    cmbBase = new QComboBox;
    fillColorList(cmbBase);
    connect(cmbBase, SIGNAL(activated(int)), this, SLOT(showBase()));

    QGridLayout *mainLayout = new QGridLayout(frameCtrl);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(labWindow, 0, 0);
    mainLayout->addWidget(cmbWindow, 0, 1);
    mainLayout->addWidget(labWindowText, 1, 0);
    mainLayout->addWidget(cmbWindowText, 1, 1);
    mainLayout->addWidget(labButton, 2, 0);
    mainLayout->addWidget(cmbButton, 2, 1);
    mainLayout->addWidget(labButtonText, 3, 0);
    mainLayout->addWidget(cmbButtonText, 3, 1);
    mainLayout->addWidget(labBase, 4, 0);
    mainLayout->addWidget(cmbBase, 4, 1);
}

void Dialog::createContentFrame()
{
    frameContent = new QFrame;

    labValue = new QLabel(tr("请选择一个值:"));
    cmbValue = new QComboBox;
    labStr = new QLabel(tr("请输入一个字符串:"));
    lineEdit = new QLineEdit;
    textEdit = new QTextEdit;

    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(labValue, 0, 0);
    topLayout->addWidget(cmbValue, 0, 1);
    topLayout->addWidget(labStr, 1, 0);
    topLayout->addWidget(lineEdit, 1, 1);
    topLayout->addWidget(textEdit, 2, 0, 1, 2);

    btnOk = new QPushButton(tr("确认"));
    btnCancel = new QPushButton(tr("取消"));

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(btnOk);
    bottomLayout->addWidget(btnCancel);

    QVBoxLayout *mainLayout = new QVBoxLayout(frameContent);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
}

void Dialog::showWindow()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[cmbWindow->currentIndex()]);
    QPalette p = frameContent->palette();
    p.setColor(QPalette::Window, color);
    frameContent->setPalette(p);
    frameContent->update();
}

void Dialog::showWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[cmbWindowText->currentIndex()]);
    QPalette p = frameContent->palette();
    p.setColor(QPalette::WindowText, color);
    frameContent->setPalette(p);
}

void Dialog::showButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[cmbButton->currentIndex()]);
    QPalette p = frameContent->palette();
    p.setColor(QPalette::Button, color);
    frameContent->setPalette(p);
    frameContent->update();
}

void Dialog::showButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[cmbButtonText->currentIndex()]);
    QPalette p = frameContent->palette();
    p.setColor(QPalette::ButtonText, color);
    frameContent->setPalette(p);
}

void Dialog::showBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[cmbBase->currentIndex()]);
    QPalette p = frameContent->palette();
    p.setColor(QPalette::Base, color);
    frameContent->setPalette(p);
}

void Dialog::fillColorList(QComboBox *comboBox)
{
    QStringList colorList = QColor::colorNames();
    QString color;
    foreach (color, colorList) {
        QPixmap pix(QSize(70, 20));
        pix.fill(QColor(color));
        comboBox->addItem(QIcon(pix), NULL);
        comboBox->setIconSize(QSize(70, 20));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}
