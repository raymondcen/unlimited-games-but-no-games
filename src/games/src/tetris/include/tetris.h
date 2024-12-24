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
#include "settings.h"
#include "block.h"


class Tetris : public Game {
private:

int score;
int high_score;

public:

Tetris();
~Tetris();

void run_game();

};
