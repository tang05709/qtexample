#include "widget.h"
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("各种标准对话框实例"));
    btnFile = new QPushButton;
    btnFile->setText(tr("文件标准对话框实例"));
    leFile = new QLineEdit;

    btnColor = new QPushButton;
    btnColor->setText(tr("颜色标准对话框实例"));
    frameColor = new QFrame;
    frameColor->setFrameShape(QFrame::Box);
    frameColor->setAutoFillBackground(true);

    btnFont = new QPushButton;
    btnFont->setText(tr("字体标准对话框实例"));
    leFont = new QLineEdit;
    leFont->setText(tr("欢迎"));

    btnInput = new QPushButton;
    btnInput->setText(tr("输入标准对话框实例"));

    btnCustomDialog = new QPushButton;
    btnCustomDialog->setText(tr("用户自定义消息对话框实例"));
    label = new QLabel;
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(btnFile, 0, 0);
    mainLayout->addWidget(leFile, 0, 1);
    mainLayout->addWidget(btnColor, 1, 0);
    mainLayout->addWidget(frameColor, 1, 1);
    mainLayout->addWidget(btnFont, 2, 0);
    mainLayout->addWidget(leFont, 2, 1);
    mainLayout->addWidget(btnInput, 3, 0);
    mainLayout->addWidget(btnCustomDialog, 4, 0);
    mainLayout->addWidget(label, 4, 1);

    connect(btnFile, SIGNAL(clicked()), this, SLOT(showFile()));
    connect(btnColor, SIGNAL(clicked()), this, SLOT(showColor()));
    connect(btnFont, SIGNAL(clicked()), this, SLOT(showFont()));
    connect(btnInput, SIGNAL(clicked()), this, SLOT(showInputDlg()));
    connect(btnCustomDialog, SIGNAL(clicked()), this, SLOT(showCustomDlg()));
}

Widget::~Widget()
{
}

void Widget::showFile()
{
    QString str = QFileDialog::getOpenFileName(this, "open file dialog", "/", "c++file(*.cpp);;c file(*c);;head file(*.h);;all file(*.*)");
    leFile->setText(str);
}

void Widget::showColor()
{
    QColor color = QColorDialog::getColor(Qt::blue);
    if (color.isValid()) {
        frameColor->setPalette(QPalette(color));
    }
}

void Widget::showFont()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok);
    if (ok) {
        leFont->setFont(font);
    }
}

void Widget::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Widget::showCustomDlg()
{
    label->setText(tr("用户自定义消息对话框"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息对话框"));
    QPushButton *btnYes = customMsgBox.addButton(tr("Yes"), QMessageBox::ActionRole);
    QPushButton *btnNo = customMsgBox.addButton(tr("No"), QMessageBox::ActionRole);
    QPushButton *btnCancel = customMsgBox.addButton(QMessageBox::Cancel);
    customMsgBox.setText(tr("这是一个用户自定义消息对话框"));
    customMsgBox.exec();

    if (customMsgBox.clickedButton() == btnYes) {
        label->setText(tr("Yes按钮被点击了"));
    } else if (customMsgBox.clickedButton() == btnNo) {
        label->setText(tr("No按钮被点击了"));
    } else if (customMsgBox.clickedButton() == btnCancel) {
        label->setText(tr("Cancel按钮被点击了"));
    }
}
