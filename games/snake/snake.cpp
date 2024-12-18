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
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Ekans");
    int cellSize = 10;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();

            
            ClearBackground(RAYWHITE);

            //DrawGrid but 2D
            for(int x = 0; x < screenWidth; x += cellSize){
                DrawLine(x, 0, x, screenHeight, BLACK);
                for(int y=0; y < screenHeight; y += cellSize){
                    DrawLine(x, y, screenWidth, y, BLACK);
                }
            }

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}
