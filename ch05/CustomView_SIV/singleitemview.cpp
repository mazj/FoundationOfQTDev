#include <QGridLayout>
#include <QScrollBar>
#include "singleitemview.h"

SingleItemView::SingleItemView(QWidget *parent) : QAbstractItemView(parent)
{
    QGridLayout *layout = new QGridLayout( this->viewport() );
    label = new QLabel();

    layout->addWidget(label, 0, 0);

    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    label->setText(tr("<i>No data.</i>"));
}

void SingleItemView::updateText()
{
    switch(selectionModel()->selection().indexes().count())
    {
    case 0:
        label->setText(tr("<i>No data.</i>"));
        break;
    case 1:
        label->setText(model()->data(currentIndex()).toString());
        break;
    default:
        label->setText(tr("<i>Too many items selected.<br>Can only show one item at a time.</i>"));
        break;
    }
}

QRect SingleItemView::visualRect(const QModelIndex &index) const
{
    if (selectionModel()->selection().indexes().count() != 1)
        return QRect();
    if (currentIndex() != index)
        return QRect();
    return rect();
}

bool SingleItemView::isIndexHidden(const QModelIndex &index) const
{
    if (selectionModel()->selection().indexes().count() != 1)
        return false;
    if (currentIndex() != index)
        return false;
    return true;
}

QModelIndex SingleItemView::indexAt(const QPoint &point) const
{
    if (this->viewport()->rect().contains(point))
    {
        return currentIndex();
    }

    return QModelIndex();
}

QRegion SingleItemView::visualRegionForSelection(const QItemSelection &selection) const
{
    if (selection.indexes().count() != 1)
        return QRegion();
    if (!selection.contains(currentIndex()))
        return QRegion();
    return QRegion(rect());
}

int SingleItemView::horizontalOffset() const
{
    return horizontalScrollBar()->value();
}

int SingleItemView::verticalOffset() const
{
    return verticalScrollBar()->value();
}
QModelIndex SingleItemView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
    return currentIndex();
}
void SingleItemView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags)
{
    //do nothing
}
void SingleItemView::scrollTo(const QModelIndex &index, ScrollHint hint)
{
    //cannot scroll
}
void SingleItemView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    updateText();
}
void SingleItemView::selectionChanged(const QItemSelection &selected, const QItemSelection &deseleced)
{
    updateText();
}
