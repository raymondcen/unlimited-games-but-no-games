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

// Custom Libraries
#include "game_launcher.h"
#include "snake.h"
#include "tetris.h"
#include "pac_man.h"


int main(int argc, char** argv) {
    srand(time(NULL));

    // GameLauncher game_launcher;
    Snake snake_game;
    Tetris tetris_game;
    PacMan pac_man_game;

    std::vector<Game*> games = {&snake_game, &tetris_game, &pac_man_game};

    games[1]->run_game();

    // init launcher
    // add games to launcher
        // have an add game function or pass in games vector?
    // game_launcher.run_launcher();

    return 0;
}
