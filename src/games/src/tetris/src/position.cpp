/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "position.h"


Position::Position(int row, int column) {
    this->row = row;
    this->column = column;
}

Position::~Position() {}


int Position::get_row() { return this->row; }


int Position::get_column() { return this->column; }
