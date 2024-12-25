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


void Tetris::setup_game() {
    const int rows = 20;
    const int columns = 10;

    this->background_color = {44, 44, 127, 255};
    this->grid = Grid(rows, columns, CELL_SIZE);
    this->blocks = {L_Block(ORANGE), J_Block(BLUE), I_Block(SKYBLUE), T_Block(PURPLE),
                    O_Block(YELLOW), S_Block(RED), Z_Block(GREEN)};
    return;
}


Block Tetris::get_random_block() {
    // Block vector empty, add all blocks again
    if (blocks.empty())
        this->blocks = {L_Block(ORANGE), J_Block(BLUE), I_Block(SKYBLUE), T_Block(PURPLE),
                        O_Block(YELLOW), S_Block(RED), Z_Block(GREEN)};
        
    int random_index = rand() % this->blocks.size();

    // Get random block and remove it
    Block random_block = this->blocks[random_index];
    this->blocks.erase(blocks.begin() + random_index);

    return random_block;
}


void Tetris::run_game() {
    const int rows = 20;
    const int columns = 10;

    // Setup window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sirtet");
    SetTargetFPS(60);

    setup_game();

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(this->background_color);

        this->grid.draw_grid(START_X, START_Y, BLACK);

        EndDrawing();
    }
    CloseWindow();

    return;
}
