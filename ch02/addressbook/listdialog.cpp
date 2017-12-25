#include "listdialog.h"
#include "ui_listdialog.h"

#include "editdialog.h"

ListDialog::ListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListDialog)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(addItem()));
    connect(ui->editButton, SIGNAL(clicked(bool)), this, SLOT(editItem()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteItem()));
}

ListDialog::~ListDialog()
{
    delete ui;
}

void ListDialog::addItem()
{
    EditDialog dlg(this);

    if (dlg.exec() == QDialog::Accepted)
        ui->list->addItem(dlg.name() + " -- " + dlg.number());
}

void ListDialog::deleteItem()
{
    delete ui->list->currentItem();
}

void ListDialog::editItem()
{
    if (!ui->list->currentItem())
        return;

    QStringList parts = ui->list->currentItem()->text().split("--");

    EditDialog dlg(this);
    dlg.setName(parts[0].trimmed());
    dlg.setNumber(parts[1].trimmed());

    if (dlg.exec() == QDialog::Accepted)
        ui->list->currentItem()->setText(dlg.name() + " -- " + dlg.number());
}
