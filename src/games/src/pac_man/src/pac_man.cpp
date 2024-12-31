/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "pac_man.h"




PacMan::PacMan() {

    num_columns=19;
    num_rows = 22;
    cell_size = 35;
}


PacMan::~PacMan() {}


void PacMan::run_game() {
    InitWindow(1920, 1080, "NAM-CAP");
    SetTargetFPS(60);
    ToggleFullscreen();
    initiate_map();

    while (!WindowShouldClose()) {

        BeginDrawing();

            draw_grid2(0,0);

        EndDrawing();
    }

    CloseWindow();
}


//testing pruposes
void PacMan::draw_grid2(int start_x, int start_y) {

    // Draw each square for the grid
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
           
            if(map[i][j] == 1){
                DrawRectangle(j * cell_size + start_x + 1, i * cell_size + start_y + 1, 
                                cell_size - 1, cell_size - 1, BLUE);
            }

            if(map[i][j] == 0){
                DrawRectangle(j * cell_size + start_x + 1, i * cell_size + start_y + 1, 
                                cell_size - 1, cell_size - 1, BLACK);
            }
        }
    }
    return;
}

void PacMan::initiate_map(){
    
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