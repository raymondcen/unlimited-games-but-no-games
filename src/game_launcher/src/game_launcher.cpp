/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "game_launcher.h"


GameLauncher::GameLauncher() {}


GameLauncher::~GameLauncher() {}



int GameLauncher::run_launcher(int argc, char** argv) {
    // QGuiApplication app(argc, argv);
    // QQmlApplicationEngine engine;

    // const QUrl url(QStringLiteral("qrc:/resources/qml/mainWindow.qml"));

    // QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //                  &app, [url](QObject *obj, const QUrl &objUrl) {
    //     if (!obj && url == objUrl) {
    //         qDebug() << "Failed to load QML file";
    //         QCoreApplication::exit(-1);
    //     }
    // }, Qt::QueuedConnection);

    // engine.load(url);

    // // Run app
    // return app.exec();
}