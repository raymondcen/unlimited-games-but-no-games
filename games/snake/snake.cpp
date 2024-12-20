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
    body_pos = {Vector2{2,3}, Vector2{3,3}};
    direction = {0,1};
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


    SetTargetFPS(60);              
    double lastTime = GetTime();
    double move_interval = 0.2; 
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        double currTime = GetTime();
        if (currTime - lastTime >= move_interval) {
            //update snake to move and add segments
            updateSnake();
            lastTime = currTime;
        }

        BeginDrawing();

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
    if((IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT) || IsKeyReleased(KEY_RIGHT)) && direction.x != -1){
        direction = {1,0};

    }else if((IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT) || IsKeyReleased(KEY_LEFT)) && direction.x != 1){
        direction = {-1,0};
    
    }else if((IsKeyPressed(KEY_UP) || IsKeyDown(KEY_UP) || IsKeyReleased(KEY_UP)) && direction.y != 1){
        direction = {0,-1};
    
    }else if((IsKeyPressed(KEY_DOWN) || IsKeyDown(KEY_DOWN) || IsKeyReleased(KEY_DOWN)) && direction.y != -1){
        direction = {0,1};
    }
    body_pos.pop_back();
    body_pos.push_front(Vector2Add(body_pos[0], direction));
}


