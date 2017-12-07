#include "eventwidget.h"
#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextEdit log;
    EventWidget w;

    QObject::connect(&w, SIGNAL(gotEvent(const QString&)), &log, SLOT(append(const QString&)));

    log.show();
    w.show();

    return a.exec();
}

