#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include <QTimer>

class Sensor : public QObject
{
    Q_OBJECT
public:
    explicit Sensor(QObject *parent = nullptr);

    int sensorValue;

    QTimer *timer;

    Q_INVOKABLE int getsensorValue();


    public slots:
        void updatevalue();
signals:

};

#endif // SENSOR_H
