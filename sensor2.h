#ifndef SENSOR2_H
#define SENSOR2_H

#include <QObject>
#include <QTimer>

class Sensor2 : public QObject
{
    Q_OBJECT
public:
    explicit Sensor2(QObject *parent = nullptr);

    int sensorValue2;

    QTimer *timer;

    Q_INVOKABLE int getsensorValue();


    public slots:
        void updatevalue();
signals:

};

#endif // SENSOR_H
