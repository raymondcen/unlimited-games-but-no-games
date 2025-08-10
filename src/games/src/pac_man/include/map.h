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
#include <vector>


// Raylib Libraries
#include <raylib.h>
#include <raymath.h>


#define sw 1240
#define sh 980

class Map {
private:
    int map[22][19];
    int num_columns;
    int num_rows;
    int cell_size;

    int mid_map_x;
    int mid_map_y;
    
    bool mapDrawn = false;

public:
    Map();
    ~Map();
    void draw_map(int, int);
    void initiate_map();

    int mid_mapx_get(){return mid_map_x;};
    int mid_mapy_get(){return mid_map_y;};
    int cellsize_get(){return cell_size;};
    int numcol_get(){return num_columns;};
    int numrow_get(){return num_rows;};
    int get_cell(int row, int col) const { return map[row][col]; }


};