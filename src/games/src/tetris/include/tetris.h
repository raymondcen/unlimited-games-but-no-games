/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once


// Raylib Libraries
#include <raylib.h>

// Standard Libraries

// Custom Libraries
#include "game.h"
#include "grid.h"


class Tetris : public Game {
private:


public:
Tetris();
~Tetris();

void run_game();

};
