/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "pac_man.h"

#define GRID_WIDTH 15
#define GRID_HEIGHT 17
#define CELL_SIZE 14*4
#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 900


PacMan::PacMan() {
    
}


PacMan::~PacMan() {}


void PacMan::run_game() {
    InitWindow(GRID_WIDTH*CELL_SIZE, GRID_HEIGHT*CELL_SIZE, "NAM-CAP");
    SetTargetFPS(60);


    while (!WindowShouldClose()) {

        BeginDrawing();

        

        EndDrawing();
    }

    CloseWindow();
}
