#include "sortonsecondmodel.h"

SortOnSecondModel::SortOnSecondModel(QObject *parent) : QSortFilterProxyModel(parent)
{

}

bool SortOnSecondModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    QString leftString = sourceModel()->data(source_left).toString();
    QString rightString = sourceModel()->data(source_right).toString();

    if (!leftString.isEmpty())
        leftString = leftString.mid(1);

    if (!rightString.isEmpty())
        rightString = rightString.mid(1);

    return leftString < rightString;
}
