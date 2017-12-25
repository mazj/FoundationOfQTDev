#include <QTableView>
#include <QSplitter>
#include <QStandardItemModel>

#include "dialog.h"
#include "singleitemview.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QTableView *table = new QTableView;
    SingleItemView *selectionView = new SingleItemView;

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
    selectionView->setModel(model);
    selectionView->setSelectionModel(table->selectionModel());

    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(table);
    splitter->addWidget(selectionView);

    setMinimumSize(600, 500);
}

Dialog::~Dialog()
{

}
