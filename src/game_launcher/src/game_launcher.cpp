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

void GameLauncher::initializeLauncher() {}

void GameLauncher::addGame(Game *new_game) {}

QString GameLauncher::getMainWindowPath() const { return (QString(QML_DIR) + "/MainWindow.qml"); }
