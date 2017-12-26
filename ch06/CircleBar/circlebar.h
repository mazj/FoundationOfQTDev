#ifndef CIRCLEBAR_H
#define CIRCLEBAR_H

#include <QWidget>

class CircleBar : public QWidget
{
    Q_OBJECT
public:
    explicit CircleBar(int value = 0, QWidget *parent = nullptr);

    int value() const;

    int heightForWidth(int) const;
    QSize sizeHint() const;

signals:
    void valueChanged(int);
public slots:
    void setValue(int);

protected:
    void paintEvent(QPaintEvent *);
    void wheelEvent(QWheelEvent *);

private:
    int m_value;
};

#endif // CIRCLEBAR_H
