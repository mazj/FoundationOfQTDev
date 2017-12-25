#ifndef INTMODEL_H
#define INTMODEL_H

#include <QObject>
#include <QList>
#include <QAbstractListModel>

class IntModel : public QAbstractListModel
{
public:
    IntModel(int count, QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

private:
    QList<int> m_values;
};

#endif // INTMODEL_H
