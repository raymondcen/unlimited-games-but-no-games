/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once


// Raylib Libraries
#include <raylib.h>

// Standard Libraries
#include <vector>
#include <iostream>

class Grid {
private:

std::vector<std::vector<int>> grid;

int num_rows;
int num_columns;
int cell_size;

public:

Grid(int rows, int cols, int cell_size);
~Grid();

void initialize_grid();
void draw_grid();


};
