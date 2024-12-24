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
Parent Block Function Definitions
*/


Block::Block() {}


Block::Block(Color color) {
    this->cell_size = 40;
    this->rotate_state = 0;
    this->color = color;
}


Block::~Block() {}


/*
L Block function definitions
*/

void L_Block::draw_block() {

}

L_Block::L_Block(Color color) {
    this->id = 1;
    this->color = color;

    // Rotation states
    this->cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
    this->cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    this->cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    this->cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
}
