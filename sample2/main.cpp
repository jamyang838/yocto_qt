#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QElapsedTimer>
//#include <QtDebug>


int main(int argc, char *argv[])
{
    QElapsedTimer timer;


    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //**************************
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    QString sss = ports[1].portName();

    QSerialPort port;
    port.setPort(ports[1]);
    port.open(QIODevice::ReadWrite);
    port.setBaudRate(QSerialPort::Baud9600);
    port.setDataBits(QSerialPort::Data8);
    port.setParity(QSerialPort::NoParity);
    port.setStopBits(QSerialPort::OneStop);
    port.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray output;
    while(true)
          {
            output = "abcd";
            port.write(output);
            port.flush();
            //timer.start();

            port.waitForBytesWritten(100);
            //port.waitForReadyRead(100);
            }
    port.close();

//**************************
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
