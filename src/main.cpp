/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


// Qt Libraries
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QObject>

// Standard Libraries
#include <iostream>

// Custom Libraries
#include "snake.h"
#include "tetris.h"


int main(int argc, char** argv) {
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

    Snake snake_game;
    Tetris tetris_game;


    //snake_game.run_game();
    tetris_game.run_game();

    return 0;
}
