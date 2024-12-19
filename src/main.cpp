/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QObject>

#include <iostream>

#include "snake.h"


int main(int argc, char** argv) {
    Snake snake_game;
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
    snake_game.run_game();

    return 0;
}
