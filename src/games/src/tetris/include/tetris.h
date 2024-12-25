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
    Block current_block;
    Block next_block;

    int score;
    int high_score;

public:
    Tetris();
    ~Tetris();
    std::vector<Block> get_all_blocks();
    void setup_game();
    Block get_random_block();
    bool block_outside();
    void draw_game();
    void move_left();
    void move_right();
    void move_down();
    void rotate_block();
    void move_to_bottom();
    void handle_input();
    void run_game();
};
