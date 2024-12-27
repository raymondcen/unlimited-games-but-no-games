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
    // Snake snake_game;        DONE
    Tetris tetris_game;
    PacMan pac_man_game;

    // tetris_game.run_game();

    // init launcher
    // add games to launcher
    // game_launcher.run_launcher();

    return 0;
}
