#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void updateLabel();
private:
    QLabel *labX;
    QLabel *labXValue;
    QLabel *labY;
    QLabel *labYValue;
    QLabel *labFrm;
    QLabel *labFrmValue;
    QLabel *labPos;
    QLabel *labPosValue;
    QLabel *labGeo;
    QLabel *labGeoValue;
    QLabel *labWidth;
    QLabel *labWidthValue;
    QLabel *labHeight;
    QLabel *labHeightValue;
    QLabel *labRect;
    QLabel *labRectValue;
    QLabel *labSize;
    QLabel *labSizeValue;
    QGridLayout *mainLayout;
protected:
    void moveEvent(QMoveEvent *) override;
    void resizeEvent(QResizeEvent *) override;

};
#endif // DIALOG_H
