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
#include <iostream>
#include <stdlib.h>
#include <string>

// Custom Libraries
#include "game.h"
#include "grid.h"
#include "settings.h"
#include "block.h"


typedef enum GameScreen { TITLE = 0, GAMEPLAY, EXIT, PLAY_AGAIN } GameScreen;


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

    // UI variables
    GameScreen current_screen;
    Texture2D title_image;
    bool user_exit;

    // Game functionality functions
    void setup_game(int rows, int columns);
    std::vector<Block> get_all_blocks();
    void reset_game();
    Block get_random_block();
    bool block_outside();
    bool block_fits();
    void calculate_full_row_score(int full_rows);
    void get_next_block();
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

    // Game UI functions
    void draw_score();
    void draw_next_block();
    void draw_game();
    void draw_title_screen();
    void draw_exit_screen();
    void draw_play_again_screen();
    void get_current_screen();
    void display_current_screen();

public:
    Tetris();
    ~Tetris();
    void run_game() override;

};
