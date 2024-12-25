/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "grid.h"


Grid::Grid() {}


Grid::Grid(int rows, int cols, int cell_size) {
    // Set grid size and initialize grid vector
    this->num_rows = rows;
    this->num_columns = cols;
    this->cell_size = cell_size;
    this->initialize_grid();
}


Grid::~Grid() {}


void Grid::initialize_grid() {
    // Resize vector
    this->grid.resize(this->num_rows);

    for (int i = 0 ; i < this->num_rows; i++)
        this->grid[i].resize(num_columns);

    // Initialize all entries to 0
    for (int i = 0; i < this->num_rows; i++) {
        for (int j = 0; j < this->num_columns; j++) {
            this->grid[i][j] = 0;
        }
    }
}


void Grid::draw_grid(int start_x, int start_y, Color color) {
    // Draw each square for the grid
    for (int i = 0; i < this->num_rows; i++) {
        for (int j = 0; j < this->num_columns; j++) {
            DrawRectangle(j * this->cell_size + start_x + 1, i * this->cell_size + start_y + 1, 
                          this->cell_size - 1, this->cell_size - 1, color);
        }
    }
}
