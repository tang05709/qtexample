#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QGradient>
#include "paintarea.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    PaintArea *paintArea;

    QLabel *labShape;
    QComboBox *cmbShape;
    QLabel *labPenWidth;
    QSpinBox *spbPenWidth;
    QLabel *labPenColor;
    QFrame *framePenColor;
    QPushButton *btnPenColor;
    QLabel *labPenStyle;
    QComboBox *cmbPenStyle;
    QLabel *labPenCap;
    QComboBox *cmbPenCap;
    QLabel *labPenJoin;
    QComboBox *cmbPenJoin;
    QLabel *labFillRule;
    QComboBox *cmbFillRule;
    QLabel *labSpread;
    QComboBox *cmbSpread;
    QGradient::Spread spread;
    QLabel *labBrushStyle;
    QComboBox *cmbBrushStyle;
    QLabel *labBrushColor;
    QFrame *frameBrushColor;
    QPushButton *btnBrushColor;
    QGridLayout *rightLayout;

protected slots:
    void showShape(int);
    void showPenWidth(int);
    void showPenColor();
    void showPenStyle(int);
    void showPenCap(int);
    void showPenJoin(int);
    void showSpreadStyle();
    void showFillRule();
    void showBrushColor();
    void showBrush(int);
};
#endif // WIDGET_H
