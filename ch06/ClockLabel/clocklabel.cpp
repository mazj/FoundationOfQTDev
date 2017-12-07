#include <QTimer>
#include <QTime>
#include "clocklabel.h"

ClockLabel::ClockLabel(QWidget *parent)
    : QLabel(parent)
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    timer->start();
    updateTime();
}

ClockLabel::~ClockLabel()
{

}

void ClockLabel::updateTime()
{
    setText(QTime::currentTime().toString());
}
