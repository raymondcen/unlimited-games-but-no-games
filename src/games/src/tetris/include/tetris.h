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
    // Game variables
    Color background_color;
    Grid grid;
    std::vector<Block> blocks;
    Block current_block;
    Block next_block;

    double current_time;
    double last_update_time;
    bool game_over;
    int score;
    int high_score;

    // Game editing methods
    std::vector<Block> get_all_blocks();
    void setup_game(int rows, int columns);
    void reset_game();
    Block get_random_block();
    bool block_outside();
    bool block_fits();
    void calculate_full_row_score(int full_rows);
    void get_next_block();
    void draw_game();
    void move_left();
    void move_right();
    void move_down();
    void rotate_block();
    void move_to_bottom();
    void handle_input();
    void move_block_down(double interval);
    bool full_row(int row);
    void move_row_down(int row, int num_rows);
    void clear_row(int row);
    int clear_full_rows();

public:
    Tetris();
    ~Tetris();
    void run_game() override;

};
