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
    Q_UNUSED(event);

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

void EventWidget::keyPressEvent(QKeyEvent *event)
{
    Qt::KeyboardModifiers m = event->modifiers();
    QString t = event->text();

    emit(gotEvent(QString("keyPressEvent(text:%1, modifiers:%2)")
                  .arg(t)
                  .arg(m                            == 0 ? tr("NoModifier"):(
                      ((m & Qt::ShiftModifier)       == 0 ? tr("") : tr("ShiftModifier ")) +
                      ((m & Qt::ControlModifier)     == 0 ? tr("") : tr("ControlModifier")) +
                      ((m & Qt::AltModifier)         == 0 ? tr("") : tr("AltModifier")) +
                      ((m & Qt::MetaModifier)        == 0 ? tr("") : tr("MetaModifier")) +
                      ((m & Qt::KeypadModifier)      == 0 ? tr("") : tr("KeypadModifier")) +
                      ((m & Qt::GroupSwitchModifier) == 0 ? tr("") : tr("GroupSwitchModifer"))                                                                                                     ))
                  ));
}

void EventWidget::keyReleaseEvent(QKeyEvent *event)
{
    Qt::KeyboardModifiers m = event->modifiers();
    QString t = event->text();

    emit(gotEvent(QString("keyReleaseEvent(text:%1, modifiers:%2)")
                  .arg(t)
                  .arg(m                            == 0 ? tr("NoModifier"):(
                      ((m & Qt::ShiftModifier)       == 0 ? tr("") : tr("ShiftModifier ")) +
                      ((m & Qt::ControlModifier)     == 0 ? tr("") : tr("ControlModifier")) +
                      ((m & Qt::AltModifier)         == 0 ? tr("") : tr("AltModifier")) +
                      ((m & Qt::MetaModifier)        == 0 ? tr("") : tr("MetaModifier")) +
                      ((m & Qt::KeypadModifier)      == 0 ? tr("") : tr("KeypadModifier")) +
                      ((m & Qt::GroupSwitchModifier) == 0 ? tr("") : tr("GroupSwitchModifer"))                                                                                                     ))
                  ));
}


void EventWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit(gotEvent(QString("mouseDoubleClickEvent(x:%1, y:%2, button:%3)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->button() == Qt::LeftButton ?   "LeftButton" :
                       (event->button() == Qt::RightButton ? "RightButton" :
                       (event->button() == Qt::MidButton ?   "MidButton" :
                       (event->button() == Qt::XButton1 ?    "XButton1" :
                                                             "XButton2"))))));
}

void EventWidget::wheelEvent(QWheelEvent *event)
{
    emit(gotEvent(QString("wheelEvent(x:%1, y:%2, delta:%3, orientation:%4)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->delta())
                  .arg(event->orientation() == Qt::Horizontal ?   "Horizontal" :
                                                                  "Vertical")));
}

void EventWidget::mouseMoveEvent(QMouseEvent *event)
{
    emit(gotEvent(QString("mouseMoveEvent(x:%1, y:%2, button:%3)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->button() == Qt::LeftButton ?   "LeftButton" :
                       (event->button() == Qt::RightButton ? "RightButton" :
                       (event->button() == Qt::MidButton ?   "MidButton" :
                       (event->button() == Qt::XButton1 ?    "XButton1" :
                                                             "XButton2"))))));
}

void EventWidget::mousePressEvent(QMouseEvent *event)
{
    emit(gotEvent(QString("mousePressEvent(x:%1, y:%2, button:%3)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->button() == Qt::LeftButton ?   "LeftButton" :
                       (event->button() == Qt::RightButton ? "RightButton" :
                       (event->button() == Qt::MidButton ?   "MidButton" :
                       (event->button() == Qt::XButton1 ?    "XButton1" :
                                                             "XButton2"))))));
}

void EventWidget::mouseReleaseEvent(QMouseEvent *event)
{
    emit(gotEvent(QString("mouseReleaseEvent(x:%1, y:%2, button:%3)")
                  .arg(event->x())
                  .arg(event->y())
                  .arg(event->button() == Qt::LeftButton ?   "LeftButton" :
                       (event->button() == Qt::RightButton ? "RightButton" :
                       (event->button() == Qt::MidButton ?   "MidButton" :
                       (event->button() == Qt::XButton1 ?    "XButton1" :
                                                             "XButton2"))))));
}

void EventWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("enterEvent")));
}

void EventWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("leaveEvent")));
}

void EventWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("showEvent")));
}

void EventWidget::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("hideEvent")));
}

void EventWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("resizeEvent")));
}

void EventWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("paintEvent")));
}

void EventWidget::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("focusInEvent")));
}

void EventWidget::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

    emit(gotEvent(QString("focusOutEvent")));
}
