/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once

// Standard Libraries
#include <iostream>
#include <cstdlib>


// Raylib Libraries
#include <raylib.h>
#include <raymath.h>

// Custom Libraries
#include "game.h"
#include "grid.h"



class PacMan : public Game {
    
private:
    Vector2 position;

    int map[22][19];
    int num_columns;
    int num_rows;
    int cell_size;

public:
    PacMan();
    ~PacMan();

    void run_game();
    void draw_grid2(int, int);

    void initiate_map();

};