/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "snake.h"


int Snake::snakeGame(){
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;
 
    //resize window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Ekans");
    ToggleFullscreen();

    //size of grid
    int smallGrid=120;
    int medGrid=60; //idk
    int largeGrid=60;

    int cellSize = smallGrid;

    int border= cellSize;

    


    //init snake object
    //Snake snake(screenWidth/2, screenHeight/2, 1);


    SetTargetFPS(60);              

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

            ClearBackground(BLACK);

            //draw border
            DrawRectangle(0, 0, screenWidth, border, BLUE); //top
            DrawRectangle(0, 0, border, screenHeight, BLUE); //left
            DrawRectangle(screenWidth-border, 0, screenWidth, screenHeight, BLUE); //right
            DrawRectangle(0, screenHeight-border, screenWidth, screenHeight, BLUE); //bottom

            //DrawGrid but 2D
            for (int x = border;x <= screenHeight- border;x += cellSize) {
                DrawLine(border, x, screenWidth - border, x, RED);
            }

            for (int y = border;y <= screenWidth- border;y += cellSize) {
                DrawLine(y, border, y, screenHeight -border, RED);
            }
            
            //draw snake
            //DrawRectangle(1, 1, cellSize, cellSize, GREEN); 

        EndDrawing();

    }

    CloseWindow();
}


Snake::Snake(int xpos, int ypos, int len){
    posx = xpos;
    posy= ypos;
    length = len;
}

Snake::Snake(){

}

Snake::~Snake(){
    
}