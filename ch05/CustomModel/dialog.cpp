#include <QTableView>
#include <QSplitter>
#include <QTreeView>
#include <QListView>

#include "mulmodel.h"
#include "objecttreemodel.h"
#include "intmodel.h"
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QTableView *mulTable = new QTableView();
    MulModel *mulModel = new MulModel(9, 9);
    mulTable->setModel(mulModel);

    QTreeView *objTree = new QTreeView();
    ObjectTreeModel *objTreeModel = new ObjectTreeModel(initObjectTree());
    objTree->setModel(objTreeModel);

    QListView *intList = new QListView();
    IntModel *intModel = new IntModel(25);
    intList->setModel(intModel);

    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(mulTable);
    splitter->addWidget(objTree);
    splitter->addWidget(intList);

    setMinimumSize(800, 500);
}

QObject *Dialog::initObjectTree()
{
    QObject *root = new QObject();
    root->setObjectName("root");

    QObject *child;

    QObject *foo = new QObject(root);
    foo->setObjectName("foo");

    child = new QObject(foo);
    child->setObjectName("Mark");

    child = new QObject(foo);
    child->setObjectName("Bob");

    child = new QObject(foo);
    child->setObjectName("Kent");

    QObject *bar = new QObject(root);
    bar->setObjectName("bar");

    child = new QObject(bar);
    child->setObjectName("Ole");

    child = new QObject(bar);
    child->setObjectName("Trond");

    QObject *baz = new QObject(root);
    baz->setObjectName("baz");

    child = new QObject(baz);
    child->setObjectName("mzj");

    child = new QObject(baz);
    child->setObjectName("123");

    return root;
}

Dialog::~Dialog()
{

}
