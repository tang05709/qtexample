#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QGroupBox>
#include <QtMath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    angle = 0;
    scaleValue = 5;
    shearValue = 5;
    translateValue = 50;
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(-200, -200, 400, 400);

    QPixmap *pixmap = new QPixmap(":/images/hudie.png");
    pixitem = new PixItem(pixmap);
    scene->addItem(pixitem);
    pixitem->setPos(0, 0);

    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);

    frameCtrl = new QFrame;
    createControlFrame();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(10);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(view);
    mainLayout->addWidget(frameCtrl);
    setLayout(mainLayout);
    setWindowTitle(tr("Graphics Item Transformation"));
}

Widget::~Widget()
{
}

void Widget::createControlFrame()
{
    // 旋转
    QSlider *rotateSlider = new QSlider;
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0, 360);
    QHBoxLayout *rotateLayout = new QHBoxLayout;
    rotateLayout->addWidget(rotateSlider);
    QGroupBox *rotateGroup = new QGroupBox(tr("Rotate"));
    rotateGroup->setLayout(rotateLayout);

    // 缩放
    QSlider *scaleSlider = new QSlider;
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0, 2 * scaleValue);
    scaleSlider->setValue(scaleValue);
    QHBoxLayout *scaleLayout = new QHBoxLayout;
    scaleLayout->addWidget(scaleSlider);
    QGroupBox *scaleGroup = new QGroupBox(tr("Scale"));
    scaleGroup->setLayout(scaleLayout);

    // 切边
    QSlider *shearSlider = new QSlider;
    shearSlider->setOrientation(Qt::Horizontal);
    shearSlider->setRange(0, 2 * shearValue);
    shearSlider->setValue(shearValue);
    QHBoxLayout *shearLayout = new QHBoxLayout;
    shearLayout->addWidget(shearSlider);
    QGroupBox *shearGroup = new QGroupBox(tr("Shear"));
    shearGroup->setLayout(shearLayout);

    // 位移
    QSlider *translateSlider = new QSlider;
    translateSlider->setOrientation(Qt::Horizontal);
    translateSlider->setRange(0, 2 * translateValue);
    translateSlider->setValue(translateValue);
    QHBoxLayout *translateLayout = new QHBoxLayout;
    translateLayout->addWidget(translateSlider);
    QGroupBox *translateGroup = new QGroupBox(tr("Translate"));
    translateGroup->setLayout(translateLayout);

    connect(rotateSlider, SIGNAL(valueChanged(int)), this, SLOT(slotRotate(int)));
    connect(scaleSlider, SIGNAL(valueChanged(int)), this, SLOT(slotScale(int)));
    connect(shearSlider, SIGNAL(valueChanged(int)), this, SLOT(slotShear(int)));
    connect(translateSlider, SIGNAL(valueChanged(int)), this, SLOT(slotTranslate(int)));

    // 控制面板主布局
    QVBoxLayout *frameLayout = new QVBoxLayout;
    frameLayout->setMargin(10);
    frameLayout->setSpacing(20);
    frameLayout->addWidget(rotateGroup);
    frameLayout->addWidget(scaleGroup);
    frameLayout->addWidget(shearGroup);
    frameLayout->addWidget(translateGroup);
    frameCtrl->setLayout(frameLayout);
}

void Widget::slotRotate(int v)
{
    view->rotate(v - angle);
    angle = v;
}


void Widget::slotScale(int v)
{
    qreal s;
    if (v > scaleValue) {
        s = pow(1.1, (v - scaleValue));
    } else {
        s = pow(1 / 1.1, (scaleValue - v));
    }
    view->scale(s, s);
    scaleValue = v;
}

void Widget::slotShear(int v)
{
    view->shear((v - shearValue) / 10.0, 0);
    shearValue = v;
}

void Widget::slotTranslate(int v)
{
    view->translate(v - translateValue, v - translateValue);
    translateValue = v;
}

