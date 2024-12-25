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


int main(int argc, char** argv) {
    srand(time(NULL));

    // GameLauncher game_launcher;
    Snake snake_game;
    Tetris tetris_game;

    // snake_game.run_game();
    tetris_game.run_game();

    // init launcher
    // add games to launcher
    // game_launcher.run_launcher();


    return 0;
}
