#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QTextEdit>


class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = nullptr);
    QImage img;
    QLabel *labImage;
    QTextEdit *text;

signals:

};

#endif // SHOWWIDGET_H
