#ifndef NUMERICKEYPAD_H
#define NUMERICKEYPAD_H

#include <QWidget>
#include <QLineEdit>

class NumericKeypad : public QWidget
{
    Q_OBJECT
public:
    explicit NumericKeypad(QWidget *parent = nullptr);

    const QString& text() const;

signals:
    void textChanged(const QString&);

public slots:
    void setText(const QString &text);

private slots:
    void buttonClicked(const QString &text);

private:
    QLineEdit *m_lineEdit;
    QString m_text;
};

#endif // NUMERICKEYPAD_H
