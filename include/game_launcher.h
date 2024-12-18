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

// Qt Libs
#include <QObject>

// Game Libs
#include "game_launcher.h"
#include "game.h"
#include "snake.h"
#include "tetris.h"


class GameLauncher : public QObject {
    Q_OBJECT

private:
public:
public slots:
signals:

};
