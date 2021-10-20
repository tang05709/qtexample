#ifndef MODELEX_H
#define MODELEX_H

#include <QWidget>
#include <QAbstractTableModel>

class ModelEx : public QAbstractTableModel
{

public:
    explicit ModelEx(QWidget *parent = nullptr);
    ~ModelEx();
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QVector<short> army;
    QVector<short> weaponType;
    QMap<short, QString> armyMap;
    QMap<short, QString> weaponTypeMap;
    QStringList weapon;
    QStringList header;
    void populateModel();
};
#endif // MODELEX_H
