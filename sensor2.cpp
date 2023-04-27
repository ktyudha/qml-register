#include "sensor2.h"

Sensor2::Sensor2(QObject *parent) : QObject(parent)
{
      sensorValue2 = 0;

    timer = new QTimer();
    timer->setInterval(1000);
    timer->start();

    connect(timer, &QTimer::timeout, this, &Sensor2::updatevalue);
}

int Sensor2::getsensorValue(){
   return sensorValue2 ;
}
void Sensor2::updatevalue(){
    sensorValue2 += 15;
    if (sensorValue2 > 100)
        sensorValue2 = 0;

}
