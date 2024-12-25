/****************************************************************************
 * File Name: grid.h
 * Date: 12/20/2024
 * Description: Header file for grid board class
 * Dependencies: Raylib, vector libraries 
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once


// Raylib Libraries
#include <raylib.h>

// Standard Libraries
#include <iostream>
#include <vector>

// Custom Libraries
#include "colors.h"


class Grid {
private:
    std::vector<std::vector<int>> grid;
    int num_rows;
    int num_columns;
    int cell_size;

public:
    Grid();
    Grid(int rows, int cols, int cell_size);
    ~Grid();
    void initialize_grid();
    void update_grid_cell(int x, int y, int value);
    void draw_grid(int start_x, int start_y);
    bool outside_grid(int row, int column) const;

};
