#include "serial.h"

Serial::Serial(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort();
    serialInfo = new QSerialPortInfo();

    connect(serial, &QSerialPort::readyRead,this, &Serial::slotSerialReceiveData);
}

bool Serial::connectDevice()
{
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setPortName("tty.usbserial-1420");

    serial->open(QIODevice::ReadWrite);

    if  (serial->open(QIODevice::ReadWrite))
        connectingState = true;
    else
        connectingState = false;

    return connectingState;
}

bool Serial::getConnectingState() {
    return connectingState;
}

bool Serial::disconnectDevice() {
    serial->close();
    connectingState = false;
}
void Serial::slotSerialReceiveData() {
    unsigned char dataChar;
    static int parserState = 0;
    QByteArray data = serial->read(10);

    for (int i = 0 ; i<data.length();i++) {
        dataChar = data[i];
        switch (parserState) {
        case 0:
            if (dataChar == '(') {
                dataAll.clear();
                parserState = 1;
            }
            break;

        case 1 :
            if (dataChar == ')') {
                dataAll.clear();
                parserState = 2;
            } else {
                dataAll += dataChar;
            }
            break;

        case 2:
            parserState = 0;
            emit dataReady();
            qDebug() << dataAll;
            break;

        default:
            break;
        }

    }
//    qDebug()<< "Data Serial -->"+ data;
}

QString Serial::getData() {
    return dataAll;
}
