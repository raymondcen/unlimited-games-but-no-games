/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "grid.h"


Grid::Grid(int rows, int cols, int cell_size) {
    this->num_rows = rows;
    this->num_columns = cols;
    this->cell_size = cell_size;
    this->initialize_grid();
}


Grid::~Grid() {}


void Grid::initialize_grid() {
    this->grid.resize(this->num_rows);

    for (int i = 0 ; i < this->num_rows; i++)
        this->grid[i].resize(num_columns);

    for (int i = 0; i < this->num_rows; i++) {
        for (int j = 0; j < this->num_columns; j++) {
            this->grid[i][j] = 0;
        }
    }
}


void Grid::draw_grid() {
    for (int i = 0; i < this->num_rows; i++) {
        for (int j = 0; j < this->num_columns; j++) {
            DrawRectangle(j * this->cell_size + 1, i * this->cell_size + 1, this->cell_size - 1, this->cell_size - 1, BLACK);
        }
    }
}


void Grid:: draw_square(int row, int col, Color color){
    DrawRectangle(col * this->cell_size + 1, row * this->cell_size + 1, this->cell_size - 1, this->cell_size - 1, color);
}