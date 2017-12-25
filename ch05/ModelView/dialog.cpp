#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QStandardItemModel>
#include <QStringListModel>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //setup view
    QTreeView *tree = new QTreeView;
    QListView *list = new QListView;
    QTableView *table = new QTableView;
    QListView *stringList = new QListView;

    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(tree);
    splitter->addWidget(list);
    splitter->addWidget(table);
    splitter->addWidget(stringList);

    //setup model
    QStandardItemModel *model = new QStandardItemModel(5, 2);
    for (int r=0; r < 5; r++)
        for (int c=0; c < 2; c++)
        {
            QStandardItem *item = new QStandardItem(QString("R%1C%2").arg(r).arg(c));

            if (c == 0)
                for (int i = 0; i < 3; i++)
                {
                    //limiting editing
                    QStandardItem *child = new QStandardItem(QString("I%1").arg(i));
                    child->setEditable(false);
                    item->appendRow(child);
                }

            model->setItem(r, c, item);
        }
    //connect view with model
    tree->setModel(model);
    list->setModel(model);
    table->setModel(model);

    //share selection model
    list->setSelectionModel(tree->selectionModel());
    table->setSelectionModel(tree->selectionModel());

    //setup model headers
    model->setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Phone Number"));

    //change selection behavior
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);

    //string list model
    QStringListModel *stringListModel = new QStringListModel();
    QStringList *strings = new QStringList();

    *strings << "Huey" << "Dewey" << "Louie";

    stringListModel->setStringList(*strings);
    stringList->setModel(stringListModel);
}

Dialog::~Dialog()
{

}
