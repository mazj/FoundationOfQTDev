#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>

class EventWidget : public QWidget
{
    Q_OBJECT

public:
    EventWidget(QWidget *parent = 0);
    ~EventWidget();
signals:
    void gotEvent(const QString &);

protected:
    void closeEvent(QCloseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

};

#endif // EVENTWIDGET_H
