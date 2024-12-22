/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "tetris.h"


Tetris::Tetris() {}


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
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int rows = 20;
    const int columns = 10;

    // make grid with 20 and 10

    // Setup window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Sirtet");
    SetTargetFPS(60);

    Color dark_blue = {44, 44, 127, 255};

    Grid grid = Grid(rows, columns, 30);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(dark_blue);

        grid.draw_grid(BLACK);


        EndDrawing();
    }
    CloseWindow();
}
