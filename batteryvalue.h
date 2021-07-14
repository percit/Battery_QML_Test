#ifndef BATTERYVALUE_H
#define BATTERYVALUE_H
#include <QTimer>
#include <QObject>

class BatteryValue : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
    Q_PROPERTY(bool timer_ON READ timer_ON WRITE setTimer_ON NOTIFY timer_ONChanged)
public:
    explicit BatteryValue(QObject *parent = nullptr);

    int value() const;
    void setValue(const int& newValue);

    bool up() const;
    void setUp(const bool& newUp);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    bool timer_ON() const;
    void setTimer_ON(bool newTimer_ON);

public slots:

signals:
    void valueChanged(const int&);
    void upChanged(const bool&);

    void timer_ONChanged();

private:
    QTimer * m_timer;
    int m_value;
    bool m_up;

    bool m_timer_ON;
};

#endif // BATTERYVALUE_H
