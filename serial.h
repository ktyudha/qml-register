#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class Serial : public QObject
{
    Q_OBJECT

public:
    explicit Serial(QObject *parent = nullptr);
    QSerialPort *serial;
    QSerialPortInfo *serialInfo;

    bool connectingState;
    QString dataAll;

    Q_INVOKABLE bool connectDevice();
    Q_INVOKABLE bool getConnectingState();
    Q_INVOKABLE bool disconnectDevice();
    Q_INVOKABLE QString getData();

public slots:
    void slotSerialReceiveData();


signals:
    void dataReady();
};

#endif // SERIAL_H
