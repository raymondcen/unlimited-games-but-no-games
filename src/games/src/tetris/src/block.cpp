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
}


Block::~Block() {}


void Block::draw_block() {
    std::vector<Position> tiles = this->cells[rotate_state];

    // Draw shape based on grid location
    for (Position square: tiles) {
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
}


/*
 * J Block function definitions
 */
J_Block::J_Block(Color color) {
    this->id = 2;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 1), Position(0, 1), Position(1, 1), Position(2, 1)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    this->cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
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
}


/*
 * O Block function definitions
 */
O_Block::O_Block(Color color) {
    this->id = 4;
    this->color = color;

    // Only one rotation state
    this->cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
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
}


Z_Block::Z_Block(Color color) {
    this->id = 6;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    this->cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
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
}
