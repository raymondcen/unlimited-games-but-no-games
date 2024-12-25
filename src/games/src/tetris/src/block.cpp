/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "block.h"


/*
 * Parent Block function definitions
 */
Block::Block() {
    this->cell_size = CELL_SIZE;
    this->rotate_state = 0;
    this->row_offset = 0;
    this->column_offset = 0;
}


Block::~Block() {}


void Block::move_block(int rows, int columns) {
    this->row_offset += rows;
    this->column_offset += columns;
}


std::vector<Position> Block::get_cell_positions() {
    std::vector<Position> new_cells;

    // Add row and column offset to current positions
    for (Position square: this->cells[rotate_state]) {
        Position new_position = Position(square.get_row() + row_offset, square.get_column() + column_offset);
        new_cells.push_back(new_position);
    }
    return new_cells;
}


void Block::update_rotate_state(int rotates) {
    this->rotate_state = (this->rotate_state + rotates) % 4;
}


void Block::draw_block() {
    std::vector<Position> cell_positions = get_cell_positions();

    // Draw shape based on grid location
    for (Position square: cell_positions) {
        DrawRectangle(square.get_column() * cell_size + START_X, square.get_row() * cell_size + START_Y,
                      cell_size - 1, cell_size - 1, this->color);
    }
}

/*
 * L Block function definitions
 */
L_Block::L_Block(Color color) {
    this->id = 1;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    this->cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};

    // Move block to top center
    move_block(0, 3);
}


/*
 * J Block function definitions
 */
J_Block::J_Block(Color color) {
    this->id = 2;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    this->cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};

    // Move block to top center
    move_block(0, 3);
}


/*
 * I Block function definitions
 */
I_Block::I_Block(Color color) {
    this->id = 3;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
    this->cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    this->cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    this->cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};

    // Move block to top center
    move_block(-1, 3);
}


/*
 * O Block function definitions
 */
O_Block::O_Block(Color color) {
    this->id = 4;
    this->color = color;

    // Only one rotation state
    this->cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};

    // Move block to top center
    move_block(0, 4);
}


/*
 * S Block function definitions
 */
S_Block::S_Block(Color color) {
    this->id = 5;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
    this->cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    this->cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
    this->cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};

    // Move block to top center
    move_block(0, 3);
}


Z_Block::Z_Block(Color color) {
    this->id = 6;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    this->cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};

    // Move block to top center
    move_block(0, 3);
}


/*
 * T Block function definitions
 */
T_Block::T_Block(Color color) {
    this->id = 7;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    this->cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};

    // Move block to top center
    move_block(0, 3);
}
