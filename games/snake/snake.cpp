/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "snake.h"
using namespace std;

Snake::Snake(int xpos, int ypos, int len) {
    posx = xpos;
    posy= ypos;
    length = len;
}


Snake::Snake() {}


Snake::~Snake() {}


void Snake::run_game() {
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;
 
    //resize window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Ekans");
    
    // Comment out for now b/c theres no exit button
    ToggleFullscreen();

    Grid small = Grid(9, 16, 119);
    SetTargetFPS(60);              

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

            ClearBackground(BLUE);
            
            //draw grid
            small.draw_grid();
            
            //draw snake
            small.draw_square(2, 3, GREEN);
            
        EndDrawing();

    }
    
    CloseWindow();
}

