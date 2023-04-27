#include "sensor.h"

Sensor::Sensor(QObject *parent) : QObject(parent)
{
    sensorValue = 0;

    timer = new QTimer();
    timer->setInterval(1000);
    timer->start();

    connect(timer, &QTimer::timeout, this, &Sensor::updatevalue);
}

int Sensor::getsensorValue(){
   return sensorValue ;
}
void Sensor::updatevalue(){
    sensorValue += 10;
    if (sensorValue > 100)
        sensorValue = 0;

}
