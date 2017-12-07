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
