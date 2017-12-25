#ifndef BARDELEGATE_H
#define BARDELEGATE_H

#include <QObject>
#include <QAbstractItemDelegate>

class BarDelegate : public QAbstractItemDelegate
{
public:
    BarDelegate(QObject *parent = 0);

    //basic
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //editable
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // BARDELEGATE_H
