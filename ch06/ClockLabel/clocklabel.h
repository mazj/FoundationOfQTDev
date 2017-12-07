#ifndef CLOCKLABEL_H
#define CLOCKLABEL_H

#include <QWidget>
#include <QLabel>

class ClockLabel : public QLabel
{
    Q_OBJECT

public:
    ClockLabel(QWidget *parent = 0);
    ~ClockLabel();
private slots:
    void updateTime();
};

#endif // CLOCKLABEL_H
