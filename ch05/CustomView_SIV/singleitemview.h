#ifndef SINGLEITEMVIEW_H
#define SINGLEITEMVIEW_H

#include <QObject>
#include <QWidget>
#include <QAbstractItemView>
#include <QLabel>

class SingleItemView : public QAbstractItemView
{
    Q_OBJECT

public:
    SingleItemView(QWidget *parent = 0);

    QModelIndex indexAt(const QPoint &point) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
    QRect visualRect(const QModelIndex &index) const;

protected:
    int horizontalOffset() const;
    bool isIndexHidden(const QModelIndex &index) const;
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
    void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags);
    int verticalOffset() const;
    QRegion visualRegionForSelection(const QItemSelection &selection) const;
protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deseleced);
private:
    void updateText();
    QLabel *label;
};

#endif // SINGLEITEMVIEW_H
