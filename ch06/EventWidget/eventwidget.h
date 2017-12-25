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
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);

};

#endif // EVENTWIDGET_H
