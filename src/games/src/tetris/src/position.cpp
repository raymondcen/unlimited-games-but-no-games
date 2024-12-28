/****************************************************************************
 * File Name: position.cpp
 * Date: 12/27/2024
 * Description: Function definitions for Position class
 * Dependencies: Position class
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "position.h"


Position::Position(int row, int column) {
    this->row = row;
    this->column = column;
}

Position::~Position() {}


int Position::get_row() const { return this->row; }


int Position::get_column() const { return this->column; }
