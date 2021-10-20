#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Geometry"));

    labX = new QLabel(tr("X():"));
    labXValue = new QLabel;

    labY = new QLabel(tr("Y():"));
    labYValue = new QLabel;

    labFrm = new QLabel(tr("Frame:"));
    labFrmValue = new QLabel;

    labPos = new QLabel(tr("pos():"));
    labPosValue = new QLabel;

    labGeo = new QLabel(tr("geometry():"));
    labGeoValue = new QLabel;

    labWidth = new QLabel(tr("width():"));
    labWidthValue = new QLabel;

    labHeight = new QLabel(tr("height():"));
    labHeightValue = new QLabel;

    labRect = new QLabel(tr("rect():"));
    labRectValue = new QLabel;

    labSize = new QLabel(tr("size():"));
    labSizeValue = new QLabel;

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(labX, 0, 0);
    mainLayout->addWidget(labXValue, 0, 1);
    mainLayout->addWidget(labY, 1, 0);
    mainLayout->addWidget(labYValue, 1, 1);
    mainLayout->addWidget(labFrm, 2, 0);
    mainLayout->addWidget(labFrmValue, 2, 1);
    mainLayout->addWidget(labPos, 3, 0);
    mainLayout->addWidget(labPosValue, 3, 1);
    mainLayout->addWidget(labGeo, 4, 0);
    mainLayout->addWidget(labGeoValue, 4, 1);
    mainLayout->addWidget(labWidth, 5, 0);
    mainLayout->addWidget(labWidthValue, 5, 1);
    mainLayout->addWidget(labHeight, 6, 0);
    mainLayout->addWidget(labHeightValue, 6, 1);
    mainLayout->addWidget(labRect, 7, 0);
    mainLayout->addWidget(labRectValue, 7, 1);
    mainLayout->addWidget(labSize, 8, 0);
    mainLayout->addWidget(labSizeValue, 8, 1);

    updateLabel();
}

Dialog::~Dialog()
{
}

void Dialog::updateLabel()
{
    QString xStr;
    labXValue->setText(xStr.setNum(x()));

    QString yStr;
    labYValue->setText(yStr.setNum(y()));

    QString frameStr;
    QString tempFrm1, tempFrm2, tempFrm3, tempFrm4;
    frameStr = tempFrm1.setNum(frameGeometry().x()) + "," +
            tempFrm2.setNum(frameGeometry().y()) + "," +
            tempFrm3.setNum(frameGeometry().width()) + "," +
            tempFrm4.setNum(frameGeometry().height());
    labFrmValue->setText(frameStr);

    QString positionStr;
    QString tempPosition1, tempPosition2;
    positionStr = tempPosition1.setNum(pos().x()) + "," +
            tempPosition2.setNum(pos().y());
    labPosValue->setText(positionStr);

    QString geoStr;
    QString tempGeo1, tempGeo2, tempGeo3, tempGeo4;
    geoStr = tempGeo1.setNum(geometry().x()) + "," +
            tempGeo2.setNum(geometry().y()) + "," +
            tempGeo3.setNum(geometry().width()) + "," +
            tempGeo4.setNum(geometry().height());
    labGeoValue->setText(geoStr);

    QString wStr, hStr;
    labWidthValue->setText(wStr.setNum(width()));
    labHeightValue->setText(hStr.setNum(height()));

    QString rectStr;
    QString tempRect1, tempRect2, tempRect3, tempRect4;
    rectStr = tempRect1.setNum(rect().x()) + "," +
            tempRect2.setNum(rect().y()) + "," +
            tempRect3.setNum(rect().width()) + "," +
            tempRect4.setNum(rect().height());
    labRectValue->setText(rectStr);

    QString sizeStr;
    QString tempSize1, tempSize2;
    sizeStr = tempSize1.setNum(size().width()) + "," +
            tempSize2.setNum(size().height());
    labSizeValue->setText(sizeStr);
}

void Dialog::moveEvent(QMoveEvent *event)
{
    updateLabel();
}

void Dialog::resizeEvent(QResizeEvent *event)
{
    updateLabel();
}
