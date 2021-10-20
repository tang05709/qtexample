#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::Widget *ui;
    QImage image1;
    QImage image2;
    QImage image3;
};
#endif // WIDGET_H
