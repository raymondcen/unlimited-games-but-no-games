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
#include <stdlib.h>

// Custom Libraries
#include "game.h"
#include "grid.h"
#include "settings.h"
#include "block.h"


class Tetris : public Game {
private:
    Color background_color;
    Grid grid;
    std::vector<Block> blocks;
    int score;
    int high_score;

public:
    Tetris();
    ~Tetris();
    void setup_game();
    Block get_random_block();

    void run_game();

};
