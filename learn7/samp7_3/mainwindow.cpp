#include "mainwindow.h"
#include <QtMath>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();

    scene = new QGraphicsScene;
    scene->setSceneRect(-200, -200, 400, 400);
    initScene();
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);
    view->show();

    setCentralWidget(view);
    resize(550, 450);
    setWindowTitle(tr("Graphics Items"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    actNew = new QAction(tr("新建"), this);
    actClear = new QAction(tr("清除"), this);
    actExit = new QAction(tr("退出"), this);
    actAddEllipseItem = new QAction(tr("椭圆"), this);
    actAddPolygonItem = new QAction(tr("多边形"), this);
    actAddTextItem = new QAction(tr("文字"), this);
    actAddRectItem = new QAction(tr("长方形"), this);
    actAddAlphaItem = new QAction(tr("图片"), this);
    actAddFlashItem = new QAction(tr("闪烁圆"), this);
    actAddAnimationItem = new QAction(tr("星星"), this);

    connect(actNew, SIGNAL(triggered()), this, SLOT(slotNew()));
    connect(actClear, SIGNAL(triggered()), this, SLOT(slotClear()));
    connect(actExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(actAddEllipseItem, SIGNAL(triggered()), this, SLOT(slotAddEllipseItem()));
    connect(actAddPolygonItem, SIGNAL(triggered()), this, SLOT(slotAddPolygonItem()));
    connect(actAddTextItem, SIGNAL(triggered()), this, SLOT(slotAddTextItem()));
    connect(actAddRectItem, SIGNAL(triggered()), this, SLOT(slotAddRectItem()));
    connect(actAddAlphaItem, SIGNAL(triggered()), this, SLOT(slotAddAlphaItem()));
    connect(actAddFlashItem, SIGNAL(triggered()), this, SLOT(slotAddFlashItem()));
    connect(actAddAnimationItem, SIGNAL(triggered()), this, SLOT(slotAddAnimationItem()));
}

void MainWindow::createMenus()
{
    QMenu* fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(actNew);
    fileMenu->addAction(actClear);
    fileMenu->addSeparator();
    fileMenu->addAction(actExit);

    QMenu* itemsMenu = menuBar()->addMenu(tr("元素"));
    itemsMenu->addAction(actAddEllipseItem);
    itemsMenu->addAction(actAddPolygonItem);
    itemsMenu->addAction(actAddTextItem);
    itemsMenu->addAction(actAddRectItem);
    itemsMenu->addAction(actAddAlphaItem);
    itemsMenu->addAction(actAddFlashItem);
    itemsMenu->addAction(actAddAnimationItem);
}

void MainWindow::initScene()
{
    int i;
    for (i = 0; i < 3; i++) {
        slotAddEllipseItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddPolygonItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddTextItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddRectItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddAlphaItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddFlashItem();
    }
    for (i = 0; i < 3; i++) {
        slotAddAnimationItem();
    }
}

void MainWindow::slotNew()
{
    slotClear();
    initScene();
    MainWindow *newWin = new MainWindow;
    newWin->show();
}

void MainWindow::slotClear()
{
    QList<QGraphicsItem*> listItem = scene->items();
    while (!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void MainWindow::slotAddEllipseItem()
{
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(QRectF(0, 0, 80, 60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddPolygonItem()
{
    QVector<QPoint> v;
    v << QPoint(30, -15) << QPoint(0, -30) << QPoint(-30, -15) << QPoint(-30, 15) << QPoint(0, 30) << QPoint(30, 15);
    QGraphicsPolygonItem *item = new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}


void MainWindow::slotAddTextItem()
{
    QFont font("Times", 16);
    QGraphicsTextItem *item = new QGraphicsTextItem("Hello Qt");
    item->setFont(font);
    item->setDefaultTextColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddRectItem()
{
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 60, 60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setPen(pen);
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddAlphaItem()
{
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(":/images/hudie.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 380, (qrand() % int(scene->sceneRect().height())) - 380);
}

void MainWindow::slotAddFlashItem()
{
    FlashItem *item = new FlashItem;
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}

void MainWindow::slotAddAnimationItem()
{
    StarItem *item = new StarItem;
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine *timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);

    int y = (qrand() % 400) - 200;
    for (int i = 0; i < 400; i++) {
        anim->setPosAt(i / 400.0, QPointF(i - 200, y));
    }
    timeLine->start();
    scene->addItem(item);
}
