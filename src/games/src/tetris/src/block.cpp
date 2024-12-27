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
    this->id = -1;
    this->cell_size = CELL_SIZE;
    this->rotate_state = 0;
    this->row_offset = 0;
    this->column_offset = 0;
}


Block::~Block() {}


int Block::get_id() const { return this->id; }


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
    this->rotate_state = (this->rotate_state + rotates + 4) % 4;
}


void Block::draw_block(int x_offset, int y_offset) {
    std::vector<Position> cell_positions = get_cell_positions();
    std::vector<Color> colors = get_colors();

    // Draw shape based on grid location
    for (Position square: cell_positions) {
        DrawRectangle(square.get_column() * cell_size + START_X + x_offset, square.get_row() * cell_size + START_Y + y_offset,
                      cell_size - 1, cell_size - 1, colors[this->id]);
    }
}

/*
 * L Block function definitions
 */
L_Block::L_Block() {
    this->id = 1;

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
J_Block::J_Block() {
    this->id = 2;

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
I_Block::I_Block() {
    this->id = 3;

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
O_Block::O_Block() {
    this->id = 4;

    // Only one rotation state
    this->cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};

    // Move block to top center
    move_block(0, 4);
}


/*
 * S Block function definitions
 */
S_Block::S_Block() {
    this->id = 5;

    // Rotation states
    this->cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
    this->cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    this->cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
    this->cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};

    // Move block to top center
    move_block(0, 3);
}


Z_Block::Z_Block() {
    this->id = 6;

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
T_Block::T_Block() {
    this->id = 7;

    // Rotation states
    this->cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    this->cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};

    // Move block to top center
    move_block(0, 3);
}
