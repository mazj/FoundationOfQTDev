#include <QTableView>
#include <QStandardItemModel>
#include <QAbstractScrollArea>

#include "widget.h"
#include "bardelegate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTableView *table = new QTableView(this);

    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    QStandardItemModel *model = new QStandardItemModel(10, 2);

    for (int r = 0; r < 10; ++r)
    {
        QStandardItem *item = new QStandardItem(QString("Row %1").arg(r+1));
        item->setEditable(false);
        model->setItem(r, 0, item);

        model->setItem(r, 1, new QStandardItem(QString::number((r*30)%100)));
    }

    table->setModel(model);

    BarDelegate *delegate = new BarDelegate();
    table->setItemDelegateForColumn(1, delegate);

    setFixedSize(400, 500);
}

Widget::~Widget()
{

}
