#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "sensor.h"
#include "sensor2.h"
#include "serial.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

//    Sensor sensor; //tidak harus dideklarasikan
    Sensor2 sensor2;
    Serial serial;
    qmlRegisterType<Sensor, 1> ("Sensor",1 ,0, "Sensor"); //Component

    engine.rootContext()->setContextProperty("Sensor2", &sensor2);
    engine.rootContext()->setContextProperty("Serial", &serial);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
