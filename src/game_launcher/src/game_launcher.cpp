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

void GameLauncher::initialize_launcher() {}

void GameLauncher::add_game(Game *new_game) {}

int32_t GameLauncher::run_launcher(int argc, char **argv) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QString MainWindowPath = QString(QML_DIR) + "/MainWindow.qml";

    engine.load(QUrl::fromLocalFile(MainWindowPath));

    const int32_t ReturnValue = app.exec();

    return ReturnValue;
}

QString GameLauncher::getMainWindowPath() const { return (QString(QML_DIR) + "/MainWindow.qml"); }
