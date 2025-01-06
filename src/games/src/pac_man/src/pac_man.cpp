/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "pac_man.h"
#include "map.h"


PacMan::PacMan() {


}


PacMan::~PacMan() {}



void PacMan::draw_pacman(){
    
}

void PacMan::run_game() {

    InitWindow(sw, sh, "NAM-CAP");
    SetTargetFPS(60);
    //ToggleFullscreen();
    map.initiate_map();

    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(BLACK);

            map.draw_map(0,0);
            draw_pacman();

        EndDrawing();
    }

    CloseWindow();
}


