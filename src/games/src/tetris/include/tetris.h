/****************************************************************************
 * File Name: tetris.h
 * Date: 12/27/2024
 * Description: Header file for Tetris game class
 * Dependencies: Raylib, game class, settings file, grid class, block class,
 *               title image png
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
    std::vector<std::vector<std::vector<Position>>> wall_kick_data;
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
    std::vector<std::vector<std::vector<Position>>> init_wall_kick_data();
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
    Position get_wall_kick_position(int block_id, int rotate_state, int index);
    bool perform_wall_kick(int rotate_state);
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
