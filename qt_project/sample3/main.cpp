#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <wiringPi.h>
#include <wiringSerial.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
/*********************************************************/
   //**************************
    int handle = serialOpen ("/dev/ttyS0", 115200) ;

    //***************************
    wiringPiSetup() ;
    pinMode (0, OUTPUT) ;
    for (;;)
    {
        serialPuts (handle, "asd") ;
        digitalWrite (0, HIGH) ; delay (500) ;
        digitalWrite (0,  LOW) ; delay (500) ;
    }
 /* ******************************************************/
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
