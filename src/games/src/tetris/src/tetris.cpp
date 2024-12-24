/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "tetris.h"


Tetris::Tetris() {
    this->score = 0;
    this->high_score = 0;
}


Tetris::~Tetris() {}


/*
    Needed to run tetris
    - Game Loop DONE
    - Game board
    - Score tracker
    - Block generation
    - Rotate blocks
    - Gravity for blocks to fall
    - Clear full line
    - Collision detection
*/

void Tetris::run_game() {
    const int rows = 20;
    const int columns = 10;

    // Setup window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sirtet");
    SetTargetFPS(60);

    // Grid setup
    Color dark_blue = {44, 44, 127, 255};
    Grid grid = Grid(rows, columns, CELL_SIZE);

// TEST
    S_Block test = S_Block(GREEN);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(dark_blue);

        grid.draw_grid(START_X, START_Y, BLACK);

// TEST
        test.draw_block();

        EndDrawing();
    }
    CloseWindow();
}
