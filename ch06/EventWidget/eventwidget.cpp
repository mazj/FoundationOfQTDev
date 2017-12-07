#include <QCloseEvent>
#include <QEvent>

#include "eventwidget.h"

EventWidget::EventWidget(QWidget *parent)
    : QWidget(parent)
{
}

EventWidget::~EventWidget()
{

}

void EventWidget::closeEvent(QCloseEvent *event)
{
    emit(gotEvent(tr("closeEvent")));
}

void EventWidget::contextMenuEvent(QContextMenuEvent *event)
{
    emit(gotEvent(QString("contextMenuEvent(x:%1, y:%2, reason:%3)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->reason() == QContextMenuEvent::Other ? "Other" :
                       (event->reason() == QContextMenuEvent::Keyboard ? "Keyboard" :
                                                                        "Mouse"))));
}
