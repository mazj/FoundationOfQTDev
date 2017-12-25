#include <QPainter>

#include "bardelegate.h"

BarDelegate::BarDelegate(QObject *parent)
{
    Q_UNUSED(parent);
}

QSize BarDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return QSize( 45, 15 );
}

void BarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect( option.rect, option.palette.highlight() );
    }

    int value = index.model()->data( index, Qt::DisplayRole ).toInt();
    double factor = (double)value/100.0;

    painter->save();

    if (factor > 1)
    {
        painter->setBrush( Qt::red );
        factor = 1;
    }
    else
    {
        painter->setBrush(QColor(0, (int)(factor*255), 255-int(factor*255)));
    }

    painter->setPen( Qt::black );
    painter->drawRect( option.rect.x() + 2, option.rect.y() + 2,
                       (int)(factor*(option.rect.width() - 5)), option.rect.height()-5 );
    painter->drawText( option.rect.x() + 2, option.rect.y() + 2,
                       option.rect.width() - 5, option.rect.height()-5,
                       0,
                       QString::number(value));
    painter->restore();
}

QWidget *BarDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSlider *slider = new QSlider(parent);

    slider->setAutoFillBackground(true);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->installEventFilter(const_cast<BarDelegate*>(this));

    return slider;
}

void BarDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

void BarDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::DisplayRole).toInt();
    static_cast<QSlider*>(editor)->setValue(value);
}

void BarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    model->setData(index, static_cast<QSlider *>(editor)->value());
}
