/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


// Standard Libraries
#include <iostream>
#include <memory>

// Custom Libraries
#include "game_launcher.h"
#include "snake.h"
#include "tetris.h"
#include "pac_man.h"
#include "flappy_bird.h"

#define RELEASE

int main(int argc, char** argv) {
    srand(time(NULL));

    const int32_t ReturnValue = 0;
    
#ifndef RELEASE
    GameLauncher gameLauncher;
    std::unique_ptr<Game> snake_unique = std::make_unique<Snake>();
    std::unique_ptr<Game> tetris_unique = std::make_unique<Tetris>();
    std::unique_ptr<Game> pac_man_unique = std::make_unique<PacMan>();
    std::unique_ptr<Game> flappy_bird_unique = std::make_unique<FlappyBird>();

    std::vector<std::unique_ptr<Game>> games_unique_ptr;
    games_unique_ptr.push_back(std::move(snake_unique));
    games_unique_ptr.push_back(std::move(tetris_unique));
    games_unique_ptr.push_back(std::move(pac_man_unique));
    games_unique_ptr.push_back(std::move(flappy_bird_unique));

// RUN GAME TO TEST HERE
    games_unique_ptr[2]->run_game();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QString MainWindowPath = gameLauncher.getMainWindowPath();

    engine.load(QUrl::fromLocalFile(MainWindowPath));

    const int32_t ReturnValue = app.exec();
#endif
    return ReturnValue;
}
