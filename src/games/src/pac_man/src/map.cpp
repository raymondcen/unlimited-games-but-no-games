/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/

#include "map.h"
Map::Map(){
    num_columns=19;
    num_rows = 22;
    cell_size = 41;

    mid_map_x= (sw - (19*cell_size))/2;
    mid_map_y=(sh - (22*cell_size))/2;

    
}

Map::~Map(){}

void Map::draw_map(int start_x, int start_y) {

    // Draw each square for the grid
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
           
            if(map[i][j] == 1){
                DrawRectangle((j * cell_size) + mid_map_x, (i * cell_size)+5, 
                                cell_size, cell_size, BLUE);
            }

            if(map[i][j] == 0){
                DrawRectangle((j * cell_size) + mid_map_x, (i * cell_size)+5, 
                                cell_size, cell_size, BLACK);

                DrawPixel((j * cell_size) + mid_map_x, (i * cell_size)+5, WHITE);
            }
        }
    }
    return;
}


void Map::initiate_map(){
    
    int temp_map[22][19] = {    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
                                {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
                                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                                {1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
                                {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
                                {1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1},
                                {0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0},
                                {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1},
                                {0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0},
                                {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1},
                                {0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0},
                                {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1},
                                {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
                                {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
                                {1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1},
                                {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
                                {1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1},
                                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
                        };

    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 19; j++) {
            map[i][j] = temp_map[i][j];
        }
    }
}