#include <QApplication>
#include <QStringListModel>
#include <QTableView>

#include "sortonsecondmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringListModel model;
    QStringList list;
    list << "Totte" << "Alfons" << "Laban" << "Bamse" << "Skalman";
    model.setStringList(list);

    SortOnSecondModel sorter;
    sorter.setSourceModel(&model);

    QTableView table;
    table.setModel(&sorter);
    table.setSortingEnabled(true);
    table.show();

    return a.exec();
}
