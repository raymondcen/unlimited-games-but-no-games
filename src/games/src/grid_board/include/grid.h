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
#include <iostream>
#include <vector>


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
void draw_grid(Color);

<<<<<<< HEAD:games/grid_board/grid.h


=======
>>>>>>> 69bee60dd606201a59c841f3756ec0304007c1e8:src/games/src/grid_board/include/grid.h
};
