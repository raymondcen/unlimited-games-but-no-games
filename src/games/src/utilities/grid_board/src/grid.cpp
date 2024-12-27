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


int Grid::get_rows() const { return this->num_rows; }


int Grid::get_columns() const { return this->num_columns; }


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
    return;
}


void Grid::update_grid_cell(int x, int y, int value) { grid[x][y] = value; }


int Grid::get_cell(int row, int column) {
    // Check for valid row and column index
    if (row < 0 || row >= this->num_rows ||
        column < 0 || column >= this->num_columns)
        return -1;

    return this->grid[row][column];
}


void Grid::draw_grid(int start_x, int start_y) {
    std::vector<Color> colors = get_colors();
    int color_val = 0;

    // Draw each square for the grid
    for (int i = 0; i < this->num_rows; i++) {
        for (int j = 0; j < this->num_columns; j++) {
            color_val = this->grid[i][j];

            DrawRectangle(j * this->cell_size + start_x + 1, i * this->cell_size + start_y + 1, 
                          this->cell_size - 1, this->cell_size - 1, colors[color_val]);
        }
    }
    return;
}


bool Grid::outside_grid(int row, int column) const {
    if (row < 0 || row >= this->num_rows || column < 0 || column >= this->num_columns)
        return true;
    
    return false;
}
