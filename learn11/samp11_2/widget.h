#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void drawPix();
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;

    QPixmap *pix;
    QImage image;
    // 图标左上顶点的位置
    int startX;
    int startY;

    // 界面宽度和高度
    int width;
    int height;
    // 网格大小，图标移动的步进值
    int step;

};
#endif // WIDGET_H
