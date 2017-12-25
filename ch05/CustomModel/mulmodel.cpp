#include <QAbstractTableModel>

#include "mulmodel.h"

MulModel::MulModel(int rows, int columns, QObject *parent) : QAbstractTableModel(parent)
{
    m_rows = rows;
    m_columns = columns;
}

int MulModel::rowCount(const QModelIndex &parent) const
{
    return m_rows;
}

int MulModel::columnCount(const QModelIndex &parent) const
{
    return m_columns;
}

QVariant MulModel::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
    case Qt::DisplayRole:
        return (index.row() + 1) * (index.column() + 1);
    case Qt::ToolTipRole:
        return QString("%1 x %2").arg(index.row() + 1).arg(index.column() + 1);
    default:
        return QVariant();
    }
}

QVariant MulModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    return section + 1;
}

Qt::ItemFlags MulModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
