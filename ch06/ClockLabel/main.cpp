#include "clocklabel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClockLabel w;
    w.show();

    return a.exec();
}
