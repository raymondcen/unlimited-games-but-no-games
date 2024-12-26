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
    return {L_Block(), J_Block(), I_Block(), T_Block(),
            O_Block(), S_Block(), Z_Block()};
}


void Tetris::setup_game(int rows, int columns) {
    // Initialize game data
    this->current_time = 0;
    this->last_update_time = 0;
    this->score = 0;
    this->high_score = 0;

    this->background_color = {44, 44, 127, 255};
    this->grid = Grid(rows, columns, CELL_SIZE);

    this->blocks = get_all_blocks();
    this->current_block = get_random_block();
    this->next_block = get_random_block();
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


bool Tetris::block_fits() {
    std::vector<Position> cell_positions = current_block.get_cell_positions();

    // Check if any squares conflict with other blocks
    for (Position square : cell_positions) {
        if (grid.get_cell(square.get_row(), square.get_column()) != 0)
            return false;
    }
    return true;
}


void Tetris::get_next_block() {
    std::vector<Position> cell_positions = current_block.get_cell_positions();

    // Add block to grid
    for (Position square : cell_positions) {
        grid.update_grid_cell(square.get_row(), square.get_column(), current_block.get_id());
    }
    current_block = next_block;
    next_block = get_random_block();
}


void Tetris::draw_game() {
    this->grid.draw_grid(START_X, START_Y);
    this->current_block.draw_block();
}


void Tetris::move_left() {
    current_block.move_block(0, -1);

    if (block_outside() || block_fits() == false)
        current_block.move_block(0, 1);
}


void Tetris::move_right() {
    current_block.move_block(0, 1);

    if (block_outside() || block_fits() == false)
        current_block.move_block(0, -1);
}


void Tetris::move_down() {
    current_block.move_block(1, 0);

    // Outside grid or collision
    if (block_outside() || block_fits() == false) {
        current_block.move_block(-1, 0);

        get_next_block();
    }
}


//
// EDIT LATER TO SUPPORT WALL KICKS/SUPER ROTATIONS
//
void Tetris::rotate_block() {
    // O Block type, no need to rotate
    if (current_block.get_id() == 4)
        return;

    current_block.update_rotate_state(1);

    if (block_outside() || block_fits() == false)
        current_block.update_rotate_state(-1);
}


void Tetris::move_to_bottom() {
    while (!block_outside() && block_fits())
        current_block.move_block(1, 0);

    if (block_outside() || block_fits() == false)
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


void Tetris::move_block_down(double interval) {
    this->current_time = GetTime();

    // Check if time is within interval
    if (this->current_time - this->last_update_time >= interval) {
        this->last_update_time = this->current_time;

        // Move current block down one sqaure
        move_down();
    }
}


bool Tetris::full_row(int row) {
    // Check for valid row
    if (row < 0 || row >= this->grid.get_rows())
        return false;

    // Check values of each column in row
    for (int i = 0; i < this->grid.get_columns(); i++) {
        if (this->grid.get_cell(row, i) == 0)
            return false;
    }
    return true;
}


void Tetris::move_row_down(int row, int num_rows) {
    // Check for valid row
    if (row < 0 || row >= this->grid.get_rows())
        return;

    // Shift row down by num_rows and replace old row with zeroes
    for (int i = 0; i < this->grid.get_columns(); i++) {
        this->grid.update_grid_cell(row + num_rows, i, this->grid.get_cell(row, i));
        this->grid.update_grid_cell(row, i, 0);
    }
}


void Tetris::clear_row(int row) {
    // Check for valid row
    if (row < 0 || row >= this->grid.get_rows())
        return;

    // Update row with zeros
    for (int i = 0; i < this->grid.get_columns(); i++)
        this->grid.update_grid_cell(row, i, 0);
}


int Tetris::clear_full_rows() {
    int full_rows = 0;

    // Clear rows bottom up
    for (int i = this->grid.get_rows() - 1; i >= 0; i--) {
        if (full_row(i)) {
            clear_row(i);
            full_rows++;
        }
        else if (full_rows > 0)
            move_row_down(i, full_rows);
    }
    return full_rows;
}


void Tetris::run_game() {
    const int rows = 20;
    const int columns = 10;

    // Setup window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sirtet");
    SetTargetFPS(60);

    setup_game(rows, columns);

    while (!WindowShouldClose()) {
        // Get and handle block movement
        handle_input();

        // Move block down given a time interval
        move_block_down(0.4);

        clear_full_rows();

//------------------------------------

        BeginDrawing();

        ClearBackground(this->background_color);
        draw_game();

        EndDrawing();
    }
    CloseWindow();

    return;
}
