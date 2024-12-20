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
    body_pos = {Vector2{16,9}, Vector2{15,9}};
    direction = {0,1};
}

Snake::~Snake() {}


void Snake::run_game() {

    srand(time(0));
    const int screenWidth = 1920;
    const int screenHeight = 1080;
 
    //resize window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Ekans");
    
    // Comment out for now b/c theres no exit button
    ToggleFullscreen();

    //init grid
    Board grid;
    grid.boardTall = 18;
    grid.boardLong = 32;
    grid.cell_size = 59;
    Grid small = Grid(grid.boardTall, grid.boardLong, grid.cell_size);

    //snake stuff
    Color snake_color = GREEN;

    //make apple stuff
    Color apple_color = RED;
    Vector2 apple = {(float)(rand() % grid.boardLong + 1), (float)(rand() % grid.boardTall + 1)}; //random position of apple
    

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

            //draw apple
            draw_apple(grid, apple_color, apple);

            //draw snake
        
            draw_snake(grid, snake_color);

        EndDrawing();
    }
    CloseWindow();
}


void Snake::draw_snake(Board grid, Color snake_color){
    for(int i = 0; i < body_pos.size(); i++){
        float x = body_pos[i].x;
        float y = body_pos[i].y;
        DrawRectangle(x * grid.cell_size+1, y*grid.cell_size+1, grid.cell_size- 1, grid.cell_size- 1, snake_color);
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


void Snake::addSegment(Board grid){

    Vector2 endDirection = Vector2Subtract(body_pos.back(), body_pos[body_pos.size()-2]);
    Vector2 add = Vector2Add(body_pos.back(), endDirection);
    
    if (add.x < 0){
        add.x = grid.boardLong - 1; //add right
    } else if (add.x >= grid.boardLong) {
        add.x = 0;                  //add left
    } else if (add.y < 0){
        add.y = grid.boardTall - 1; //add bottom
    } else if (add.y >= grid.boardTall){
        add.y = 0;                  //add top
    }
    body_pos.push_back(add);
}




void Snake::draw_apple(Board grid, Color apple_color, Vector2& apple){

    if((body_pos[0].x == apple.x) && (body_pos[0].y == apple.y)){
       apple = {(float)(rand() % grid.boardLong), (float)(rand() % grid.boardTall)};
       addSegment(grid);
    }
    
    DrawRectangle(apple.x * grid.cell_size+1, apple.y*grid.cell_size+1, grid.cell_size- 1, grid.cell_size- 1, apple_color);

}


