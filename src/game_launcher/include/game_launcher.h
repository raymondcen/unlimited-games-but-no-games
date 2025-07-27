/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/

// Has an linked list of games
// include games header file and game.h
// Qt object

#pragma once

// Qt Libraries
#include <QObject>
#include <QtQml>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Standard Libraries


// Custom Libraries
#include "game_launcher.h"
#include "game.h"


class GameLauncher : public QObject {
    Q_OBJECT
    QML_ELEMENT
private:

protected:

public:

GameLauncher();
~GameLauncher();

void initialize_launcher();
void add_game(Game* new_game);

int32_t run_launcher(int argc, char **argv);

QString getMainWindowPath() const;

public slots:

// UI stuff

signals:

// UI changing stuff

};
