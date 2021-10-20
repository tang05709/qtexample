#include "histogramview.h"
#include <QPainter>

HistogramView::HistogramView(QWidget *parent) : QAbstractItemView(parent)
{


}

void HistogramView::paintEvent(QPaintEvent *event)
{
    QPainter painter(viewport());
    painter.setPen(Qt::black);
    int x0 = 40;
    int y0 = 250;
    // 完成x、y坐标轴的绘制，并标注坐标轴的变量
    // y坐标轴
    painter.drawLine(x0, y0, 40, 30);
    painter.drawLine(38, 32, 40, 30);
    painter.drawLine(40, 30, 42, 32);
    painter.drawText(20, 30, tr("人数"));
    for (int i = 1; i < 5; i++) {
        painter.drawLine(-1, -i * 50, 1, -i * 50);
        painter.drawText(-20, -i * 50, tr("%1").arg(i * 5));
    }

    // x坐标轴
    painter.drawLine(x0, y0, 540, 250);
    painter.drawLine(538, 248, 540, 250);
    painter.drawLine(540, 250, 538, 252);
    painter.drawText(545, 250, tr("部门"));
    int posD = x0 + 20;
    int row;
    for (row = 0; row < model()->rowCount(rootIndex()); row++) {
        QModelIndex index = model()->index(row, 0, rootIndex());
        QString dep = model()->data(index).toString();
        painter.drawText(posD, y0 + 20, dep);
        posD += 50;
    }

    // 完成表格第1列数据的柱状统计图绘制
    // 男
    int posM = x0 + 20;
    mRegionList.clear();
    for (row = 0; row < model()->rowCount(rootIndex()); row++) {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int male = model()->data(index).toDouble();
        int width = 10;
        if (selections->isSelected(index)) {
            painter.setBrush(QBrush(Qt::blue, Qt::Dense3Pattern));

        } else {
            painter.setBrush(Qt::black);
        }
        painter.drawRect(QRect(posM, y0 - male * 10, width, male * 10));
        QRegion regionM(posM, y0 - male * 10, width, male * 10);
        mRegionList.insert(row, regionM);
        posM += 50;
    }

    // 完成表格第2列数据的柱状统计图绘制
    // 女
    int posF = x0 + 30;
    fRegionList.clear();
    for (row = 0; row < model()->rowCount(rootIndex()); row++) {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int female = model()->data(index).toDouble();
        int width = 10;
        if (selections->isSelected(index)) {
            painter.setBrush(QBrush(Qt::blue, Qt::Dense3Pattern));

        } else {
            painter.setBrush(Qt::red);
        }
        painter.drawRect(QRect(posF, y0 - female * 10, width, female * 10));
        QRegion regionF(posF, y0 - female * 10, width, female * 10);
        mRegionList.insert(row, regionF);
        posF += 50;
    }

    // 完成表格第3列数据的柱状统计图绘制
    // 女
    int posS = x0 + 40;
    sRegionList.clear();
    for (row = 0; row < model()->rowCount(rootIndex()); row++) {
        QModelIndex index = model()->index(row, 1, rootIndex());
        int retire = model()->data(index).toDouble();
        int width = 10;
        if (selections->isSelected(index)) {
            painter.setBrush(QBrush(Qt::blue, Qt::Dense3Pattern));

        } else {
            painter.setBrush(Qt::green);
        }
        painter.drawRect(QRect(posF, y0 - retire * 10, width, retire * 10));
        QRegion regionS(posF, y0 - retire * 10, width, retire * 10);
        mRegionList.insert(row, regionS);
        posS += 50;
    }
}

void HistogramView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    QAbstractItemView::dataChanged(topLeft, bottomRight);
    viewport()->update();
}

void HistogramView::setSelectionModel(QItemSelectionModel *selectionModel)
{
    selections = selectionModel;
}

void HistogramView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    viewport()->update();
}

void HistogramView::mousePressEvent(QMouseEvent *event)
{
    QAbstractItemView::mousePressEvent(event);
    setSelection(QRect(event->pos().x(), event->pos().y(), 1, 1), QItemSelectionModel::SelectCurrent);
}

void HistogramView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command)
{
    int rows = model()->rowCount(rootIndex());
    int columns = model()->columnCount(rootIndex());
    QModelIndex selectedIndex;
    for (int row = 0; row < rows; ++row) {
        for (int column = 1; column < columns; ++column) {
            QModelIndex index = model()->index(row, column, rootIndex());
            QRegion region = itemRegion(index);
            if (!region.intersected(rect).isEmpty()) {
                selectedIndex = index;
            }
        }
    }

    if (selectedIndex.isValid()) {
        selections->select(selectedIndex, command);
    } else {
        QModelIndex noIndex;
        selections->select(noIndex, command);
    }
}

QModelIndex HistogramView::indexAt(const QPoint &point) const
{
    QPoint newPoint(point.x(), point.y());
    QRegion region;
    // 男
    foreach (region, mRegionList) {
        if (region.contains(newPoint)) {
            int row = mRegionList.indexOf(region);
            QModelIndex index = model()->index(row, 1, rootIndex());
            return index;
        }
    }

    // 女
    foreach (region, fRegionList) {
        if (region.contains(newPoint)) {
            int row = fRegionList.indexOf(region);
            QModelIndex index = model()->index(row, 2, rootIndex());
            return index;
        }
    }

    // 合计
    foreach (region, sRegionList) {
        if (region.contains(newPoint)) {
            int row = sRegionList.indexOf(region);
            QModelIndex index = model()->index(row, 3, rootIndex());
            return index;
        }
    }

    return QModelIndex();
}

QRect HistogramView::visualRect(const QModelIndex &index) const {}
void HistogramView::scrollTo(const QModelIndex &index, ScrollHint hint) {}
QModelIndex HistogramView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) {}
int HistogramView::horizontalOffset() const {}
int HistogramView::verticalOffset() const {}
bool HistogramView::isIndexHidden(const QModelIndex &index) const {}
QRegion HistogramView::visualRegionForSelection(const QItemSelection &selection) const {}

QRegion HistogramView::itemRegion(QModelIndex index)
{
    QRegion region;
    if (index.column() == 1) {
        region = mRegionList[index.row()];
    }
    if (index.column() == 2) {
        region = fRegionList[index.row()];
    }
    if (index.column() == 3) {
        region = sRegionList[index.row()];
    }
    return region;
}

