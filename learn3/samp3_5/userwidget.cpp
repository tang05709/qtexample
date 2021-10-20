#include "userwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

UserWidget::UserWidget(QWidget *parent)
    : QFrame(parent)
{
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);

    // 插入3个页面
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    // 创建2个按钮
    btnAmend = new QPushButton(tr("修改"));
    btnClose = new QPushButton(tr("关闭"));
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);
    btnLayout->addWidget(btnAmend);
    btnLayout->addWidget(btnClose);

    // 整体布局
    QVBoxLayout *rightLayout = new QVBoxLayout(this);
    rightLayout->setMargin(5);
    rightLayout->setSpacing(5);
    rightLayout->addWidget(stack);
    rightLayout->addLayout(btnLayout);
}

UserWidget::~UserWidget()
{
}

