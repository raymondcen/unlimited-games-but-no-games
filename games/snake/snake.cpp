/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "snake.h"


Snake::Snake() {
    body_pos = {Vector2{2,3}, Vector2{3,3}, Vector2{4,3}};
    direction = {1,0};
}

Snake::~Snake() {}


void Snake::run_game() {
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;
 
    //resize window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Ekans");
    
    // Comment out for now b/c theres no exit button
    ToggleFullscreen();

    //init grid
    int cell_size = 59;
    Grid small = Grid(18, 32, cell_size);


    //init snake
    Color snake_color = GREEN;

    double speed = 0.2;

    SetTargetFPS(60);              

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();
            //update snake to move and add segments
            WaitTime(speed);
            updateSnake();

            ClearBackground(BLUE);

            //draw grid 
            small.draw_grid();

            //draw snake
            draw_snake(cell_size, snake_color);
            
        EndDrawing();

    }
    
    CloseWindow();
}

void Snake::draw_snake(int cell_size, Color snake_color){

    for(int i = 0; i < body_pos.size(); i++){
        float x = body_pos[i].x;
        float y = body_pos[i].y;
        DrawRectangle(x * cell_size+1, y*cell_size+1, cell_size- 1, cell_size- 1, snake_color);
    }

}

void Snake::updateSnake() {
    body_pos.pop_back();
    body_pos.push_front(Vector2Add(body_pos[0], direction));
}


