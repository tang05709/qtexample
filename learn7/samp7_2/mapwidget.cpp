#include "mapwidget.h"
#include <QGraphicsScene>
#include <QSlider>
#include <QGridLayout>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QtMath>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>

MapWidget::MapWidget()
{
    readMap();
    zoom = 50;
    int width = map.width();
    int height = map.height();
    QGraphicsScene *scene = new QGraphicsScene(this);
    // 限定场景显示区域为地图大小
    scene->setSceneRect(-width / 2, -height / 2, width, height);
    setScene(scene);

    setCacheMode(CacheBackground);

    // 用于地图缩放滚动条
    QSlider *slider = new QSlider;
    slider->setOrientation(Qt::Vertical);
    slider->setRange(1, 100);
    slider->setTickInterval(10);
    slider->setValue(50);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slotZoom(int)));

    QLabel *labZoomin = new QLabel;
    labZoomin->setScaledContents(true);
    labZoomin->setPixmap(QPixmap(":/images/zoomin.png"));
    QLabel *labZoomout = new QLabel;
    labZoomout->setScaledContents(true);
    labZoomout->setPixmap(QPixmap(":/images/zoomout.png"));

    // 坐标值显示
    QLabel *lab1 = new QLabel(tr("GraphicsView:"));
    viewCoord = new QLabel;
    QLabel *lab2 = new QLabel(tr("GraphicsScene:"));
    sceneCoord = new QLabel;
    QLabel *lab3 = new QLabel(tr("Map:"));
    mapCoord = new QLabel;
    //坐标显示布局
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(lab1, 0, 0);
    gridLayout->addWidget(viewCoord, 0, 1);
    gridLayout->addWidget(lab2, 1, 0);
    gridLayout->addWidget(sceneCoord, 1, 1);
    gridLayout->addWidget(lab3, 2, 0);
    gridLayout->addWidget(mapCoord, 2, 1);
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);

    QFrame *frameCoord = new QFrame;
    frameCoord->setLayout(gridLayout);

    // 缩放控制布局
    QVBoxLayout *zoomLayout = new QVBoxLayout;
    zoomLayout->addWidget(labZoomin);
    zoomLayout->addWidget(slider);
    zoomLayout->addWidget(labZoomout);

    // 缩标显示布局
    QVBoxLayout *coordLayout = new QVBoxLayout;
    coordLayout->addWidget(frameCoord);
    zoomLayout->addStretch();

    // 主布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(zoomLayout);
    mainLayout->addLayout(coordLayout);
    mainLayout->addStretch();
    mainLayout->setMargin(30);
    mainLayout->setSpacing(10);
    setLayout(mainLayout);
    setWindowTitle(tr("Map Widget"));
    setMinimumSize(800, 600);
}

void MapWidget::readMap()
{
    QString mapName;
    QFile mapFile("maps.txt");
    int ok = mapFile.open(QIODevice::ReadOnly);
    if (ok) {
        QTextStream ts(&mapFile);
        if (!ts.atEnd()) {
            ts >> mapName;
            ts >> x1 >> y1 >> x2 >> y2;
        }
    }
    map.load(mapName);
}

void MapWidget::slotZoom(int v)
{
    qreal s;
    if (v > zoom) {
        s = pow(1.01, (v - zoom));
    } else {
        s = pow(1 / 1.01, (zoom - v));
    }
    scale(s, s);
    zoom = v;
}

void MapWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawPixmap(int(sceneRect().left()), int(sceneRect().top()), map);
}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint viewPoint = event->pos();
    viewCoord->setText(QString::number(viewPoint.x()) + "," + QString::number(viewPoint.y()));
    QPointF scenePoint = mapToScene(viewPoint);
    sceneCoord->setText(QString::number(scenePoint.x()) + "," + QString::number(scenePoint.y()));
    QPointF latLon = mapToMap(scenePoint);
    mapCoord->setText(QString::number(latLon.x()) + "," + QString::number(latLon.y()));
}

QPointF MapWidget::mapToMap(QPointF p)
{
    QPointF latLon;
    qreal w = sceneRect().width();
    qreal h = sceneRect().height();
    qreal lon = y1 - ((h / 2 + p.y()) * abs(y1 - y2) / h);
    qreal lat = x1 + ((w / 2 + p.x()) * abs(x1 - x2) / w);
    latLon.setX(lat);
    latLon.setY(lon);
    return latLon;
}

