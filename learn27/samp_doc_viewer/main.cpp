#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "HtmlHandler.h"
#include "TextHandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    qmlRegisterType<HtmlHandler>("org.qtproject.easybooks", 1, 0, "HtmlHandler");
    qmlRegisterType<TextHandler>("org.qtproject.easybooks", 1, 0, "TextHandler");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
