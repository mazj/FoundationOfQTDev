#include <QApplication>
#include <QLineEdit>

#include "keyboardfilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit lineEdit;
    KeyboardFilter filter;

    lineEdit.installEventFilter(&filter);
    lineEdit.show();

    return a.exec();
}
