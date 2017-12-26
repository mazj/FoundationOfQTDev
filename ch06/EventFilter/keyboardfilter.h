#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H

#include <QObject>

class KeyboardFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *dist, QEvent *event);

signals:

public slots:
};

#endif // KEYBOARDFILTER_H
