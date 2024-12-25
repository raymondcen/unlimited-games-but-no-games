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


std::vector<Block> Tetris::get_all_blocks() {
    return {L_Block(ORANGE), J_Block(BLUE), I_Block(SKYBLUE), T_Block(PURPLE),
            O_Block(YELLOW), S_Block(RED), Z_Block(GREEN)};
}


void Tetris::setup_game(int rows, int columns) {
    this->score = 0;
    this->high_score = 0;

    this->background_color = {44, 44, 127, 255};
    this->grid = Grid(rows, columns, CELL_SIZE);

    this->blocks = get_all_blocks();
    this->current_block = I_Block(BLUE);            // TESTING ONLY, CHANGE BACK WHEN DONE
    this->next_block = get_random_block();

    return;
}


Block Tetris::get_random_block() {
    // Block vector empty, add all blocks again
    if (blocks.empty())
        this->blocks = get_all_blocks();
        
    int random_index = rand() % this->blocks.size();

    // Get random block and remove it
    Block random_block = this->blocks[random_index];
    this->blocks.erase(blocks.begin() + random_index);

    return random_block;
}


bool Tetris::block_outside() {
    std::vector<Position> cell_positions = current_block.get_cell_positions();

    // Check if any squares are outside grid
    for (Position square : cell_positions) {
        if (grid.outside_grid(square.get_row(), square.get_column()))
            return true;
    }
    return false;
}


void Tetris::draw_game() {
    this->grid.draw_grid(START_X, START_Y, BLACK);
    this->current_block.draw_block();
}


void Tetris::move_left() {
    current_block.move_block(0, -1);

    if (block_outside())
        current_block.move_block(0, 1);

}


void Tetris::move_right() {
    current_block.move_block(0, 1);

    if (block_outside())
        current_block.move_block(0, -1);
}


void Tetris::move_down() {
    current_block.move_block(1, 0);

    if (block_outside())
        current_block.move_block(-1, 0);
}


//
// EDIT LATER TO SUPPORT WALL KICKS/SUPER ROTATIONS, ALSO HAS BUG WITH ROTATING OUT OF GRID
//
void Tetris::rotate_block() {
    current_block.update_rotate_state(1);

    if (block_outside())
        current_block.update_rotate_state(-1);
}


void Tetris::move_to_bottom() {
    while (!block_outside())
        current_block.move_block(1, 0);

    if (block_outside())
        current_block.move_block(-1, 0);
}


void Tetris::handle_input() {
    int key_pressed = GetKeyPressed();

    if (key_pressed == KEY_LEFT) {
        move_left();
    }
    else if (key_pressed == KEY_RIGHT) {
        move_right();
    }
    else if (key_pressed == KEY_DOWN) {
        move_down();
    }
    else if (key_pressed == KEY_UP) {
        rotate_block();
    }
    else if (key_pressed == KEY_SPACE) {
        move_to_bottom();
    }
}


void Tetris::run_game() {
    const int rows = 20;
    const int columns = 10;

    // Setup window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sirtet");
    SetTargetFPS(60);

    setup_game(20, 10);

    while (!WindowShouldClose()) {
        // Get and handle block movement
        handle_input();

        BeginDrawing();

        ClearBackground(this->background_color);
        draw_game();

        EndDrawing();
    }
    CloseWindow();

    return;
}
