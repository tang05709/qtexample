#include "userwidget.h"

#include <QApplication>
#include <QSplitter>
#include <QListWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 新建一个水平分隔窗口对象，作为主布局
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setOpaqueResize(true);
    // 添加左侧菜单列表
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0, QObject::tr("基本信息"));
    list->insertItem(1, QObject::tr("联系方式"));
    list->insertItem(2, QObject::tr("详细资料"));
    // 添加右侧表达stack
    UserWidget *userWidget = new UserWidget(splitterMain);
    QObject::connect(list, SIGNAL(currentRowChanged(int)), userWidget->stack, SLOT(setCurrentIndex(int)));
    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();

    return a.exec();
}
