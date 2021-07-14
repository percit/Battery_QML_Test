#include "batteryvalue.h"
#include <QDebug>
BatteryValue::BatteryValue(QObject *parent) :
    QObject(parent),
    m_timer(new QTimer(this)),
    m_value(0),
    m_up(true),
    m_timer_ON(false)
{
    qDebug() << "created battery constructor";
    m_timer->setInterval(10);
    connect(m_timer, &QTimer::timeout, [=](){ //jesli skonczy sie ten czas 500ms, to sprawdza czy jest
        if(m_up) {++m_value;} //true czy false i dodaje lub odejmuje
        else {--m_value;}
        emit valueChanged(m_value); //to nie potrzebuje body, to signal z Q_PROPERTY
    });

}



int BatteryValue::value() const
{
    if(m_value < 0) return 0;
    else if(m_value > 100) return 100;
    return m_value;
}

void BatteryValue::setValue(const int& newValue)
{
    if (m_value == newValue)
        return;
    m_value = newValue;
    emit valueChanged(m_value);
}

bool BatteryValue::up() const
{
    return m_up;
}

void BatteryValue::setUp(const bool& newUp)
{
    if (m_up == newUp)
        return;
    m_up = newUp;
    emit upChanged(m_up);
}

void BatteryValue::start()
{
    qDebug() << "mtimer started";
    if(m_timer_ON == false){
        m_timer->start();
        m_timer_ON = true;
    }
    else{
        m_timer->stop();
        m_timer_ON = false;
    }
}

void BatteryValue::stop()
{
    qDebug() << "mtimer stoped";
    if(m_timer_ON == true){
        m_timer->stop();
        m_timer_ON = false;
    }
    else{
        m_timer->start();
        m_timer_ON = true;
    }
}

bool BatteryValue::timer_ON() const
{
    return m_timer_ON;
}

void BatteryValue::setTimer_ON(bool newTimer_ON)
{
    if (m_timer_ON == newTimer_ON)
        return;
    m_timer_ON = newTimer_ON;
    emit timer_ONChanged();
}
