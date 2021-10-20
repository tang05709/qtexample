#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include <QGraphicsEllipseItem>
#include "flashitem.h"
#include "staritem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initScene(); // 初始化场景
    void createActions(); // 创建主窗体所有动作
    void createMenus(); // 创建主窗体的菜单栏

public slots:
    void slotNew(); // 新建一个显示窗体
    void slotClear(); // 清理场景中所有图元
    void slotAddEllipseItem(); // 加入一个椭圆形图元
    void slotAddPolygonItem(); // 加入一个多边形图元
    void slotAddTextItem(); // 加入一个文字图元
    void slotAddRectItem(); // 加入一个长方形图元
    void slotAddAlphaItem(); // 加入一个透明蝴蝶图片
    void slotAddFlashItem(); // 加入一个闪烁圆
    void slotAddAnimationItem(); // 加入一个移动的星星

private:
    QGraphicsScene *scene;
    QAction *actNew;
    QAction *actClear;
    QAction *actExit;
    QAction *actAddEllipseItem;
    QAction *actAddPolygonItem;
    QAction *actAddTextItem;
    QAction *actAddRectItem;
    QAction *actAddAlphaItem;
    QAction *actAddFlashItem;
    QAction *actAddAnimationItem;
};
#endif // MAINWINDOW_H
