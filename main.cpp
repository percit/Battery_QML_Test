#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "radialbar.h"
#include "batteryvalue.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    BatteryValue battery;
    qmlRegisterType<RadialBar>("CustomControls", 1, 0, "RadialBar");

    QQmlApplicationEngine engine;
    //engine.rootContext()->setContextProperty("Battery", &battery);
    qmlRegisterType<BatteryValue>("com.blikoon.batteryvalue", 1,0, "Battery");


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
