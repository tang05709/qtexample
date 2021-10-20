#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>
#include <QFileInfoList>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void showFileInfoList(QFileInfoList list);

public slots:
    void slotDirShow(QListWidgetItem *item);
    void slotShow(QDir dir);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
