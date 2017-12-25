#ifndef SORTONSECONDMODEL_H
#define SORTONSECONDMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class SortOnSecondModel : public QSortFilterProxyModel
{
public:
    SortOnSecondModel(QObject *parent = 0);
protected:
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const;
};

#endif // SORTONSECONDMODEL_H
