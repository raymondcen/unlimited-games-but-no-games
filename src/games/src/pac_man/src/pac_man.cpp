/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "pac_man.h"


PacMan::PacMan() {}


PacMan::~PacMan() {}


void PacMan::run_game() {
    InitWindow(1400, 950, "NAM-CAP");
    SetTargetFPS(60);


    while (!WindowShouldClose()) {

        BeginDrawing();

        

        EndDrawing();
    }

    CloseWindow();
}
