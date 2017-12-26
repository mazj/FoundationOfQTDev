#include <QEvent>
#include <QKeyEvent>

#include "keyboardfilter.h"

KeyboardFilter::KeyboardFilter(QObject *parent) : QObject(parent)
{

}

bool KeyboardFilter::eventFilter(QObject *dist, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        static QString digits = QString("1234567890");

        if (digits.indexOf(keyEvent->text()) != -1)
        {
            return true;
        }
    }

    return QObject::eventFilter(dist, event);
}
