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
    body_pos = {Vector2{1,1}};
    direction = {0,0};
    movement = true;


    frames = 0;
    out_bounds = false;
    snake_coll = false;

    score = 0;

    home_screen = false;
}

Snake::~Snake() {}


void Snake::run_game() {
    SetTraceLogLevel(LOG_ERROR);
    //resolution
    const int screenWidth = 1920;
    const int screenHeight = 1080;
 
    //resize window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Ekans");

    //load play again and exit button/image
    Texture2D paButton = LoadTexture("../src/games/src/snake/include/paButton.png");
    Texture2D exitButton = LoadTexture("../src/games/src/snake/include/exitButton.png");

    // Comment out for now b/c theres no exit button
    // ToggleFullscreen();

    //choose board size
    mode = 2;

    //init grid
    Board grid;

    if(mode == 1){
        //small board
        grid.boardTall = 9;
        grid.boardLong = 16;
        grid.cell_size = 120;
    }
    if(mode == 2){  
        //med board
        grid.boardTall = 18;
        grid.boardLong = 32;
        grid.cell_size = 60;
    }
    if(mode==3){
        //large board
        grid.boardTall = 27;
        grid.boardLong = 48;
        grid.cell_size = 40;
    }

    //grid variable
    Grid small = Grid(grid.boardTall, grid.boardLong, grid.cell_size);

    //snake variables
    Color snake_color = GREEN;

    //apple variaables
    Color apple_color = RED;
    Vector2 apple = {(float) (rand() % (grid.boardLong - 2 )+ 1), 
                        (float)(rand() % (grid.boardTall - 2)+ 1)}; //random position of apple

    //play again TEXT
    const char *playAgainText = "PLAY AGAIN?";
    int paWid = MeasureText(playAgainText, 120);

    //play again BUTTON/IMAGE
    int paScale = 4;
    Vector2 paPos = {(float)(GetScreenWidth() - (paButton.width*paScale))/2, 640.0f};
    Rectangle paRec = {paPos.x, paPos.y-19, (float)paButton.width * paScale, (float)paButton.height * paScale}; //idk why rectangle is offset by 19 pixels compared to the actualy DrawTexture

    //exit BUTTON/IMAGE
    int exitScale = 4;
    Vector2 exitPos = {(float)(GetScreenWidth() - (exitButton.width*exitScale))/2, (float)740};
    Rectangle exitRec = {exitPos.x, exitPos.y-19, (float)exitButton.width*exitScale, (float)exitButton.height*exitScale}; //why is it offset by 19 pixels?????????
    
    //score TEXT
    const char *scoreText = "SCORE: %04i";
    int sWid = MeasureText(scoreText, 100);
    Vector2 mousePoint= {0.0f, 0.0f};

    //set frames
    SetTargetFPS(60);              
    int per_sec = 8;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {   
        get_input();

        //move every x frames
        if(frames%per_sec == 0){
            movement = true;
            move_snake();
            out_bounds = check_bounds(grid);
            if(snake_coll == false)
                snake_coll = check_snake_coll();
        }

        //Draw everything
        BeginDrawing();

            //HOME SCREEN?
            //WIN CONDITION
            //CHANGE MODE / SETTINGS?

            if(out_bounds == true || snake_coll == true){   //end game screen
    
                mousePoint = GetMousePosition();

                //draw base 
                DrawRectangle(480, 100, 960, 880, RED); //border of base
                DrawRectangle(500, 120, 920, 840, BLUE); //inner base
                
                //DrawText(const char *text, int posX, int posY, int fontSize, Color color); 
                //draw play again and score TEXT
                DrawText(playAgainText, (GetScreenWidth() - paWid)/2, 180, 120, BLACK);
                DrawText(TextFormat(scoreText, score), (GetScreenWidth() - sWid)/2, 420, 100, GREEN);

                //DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);    
                //draw play again and exit BUTTON
                DrawTextureEx(paButton, paPos, 0.0f, (float)paScale, WHITE);
                DrawTextureEx(exitButton, exitPos, (float)0, (float)exitScale, WHITE);

                //click play again button
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, paRec)) {
                    out_bounds = false;
                    snake_coll = false;
                    body_pos = {Vector2{1,1}};
                    direction = {0,0};
                    score = 0;
                    apple = {(float) (rand() % (grid.boardLong - 2 )+ 1), 
                             (float)(rand() % (grid.boardTall - 2)+ 1)};
                }
               
                //click exit button
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, exitRec)) {
                    CloseWindow();
                }
 
            } else if(out_bounds == false && snake_coll == false && home_screen == false){
                ClearBackground(GRAY);
                 //draw grid  
                small.draw_grid(0, 0, BLACK);
                draw_borders(grid);

                //draw snake
                draw_snake(grid, snake_color);

                //draw apple
                draw_apple(grid, apple_color, apple);

            } else if(home_screen == true){

            }
        EndDrawing();
        frames++;
    }
    CloseWindow();
    UnloadTexture(paButton);
    UnloadTexture(exitButton);
}


void Snake::move_snake() {
    body_pos.pop_back();
    body_pos.push_front(Vector2Add(body_pos[0], direction));
}


void Snake::draw_snake(Board grid, Color snake_color) {
    for(int i = 0; i < body_pos.size(); i++){
        float x = body_pos[i].x;
        float y = body_pos[i].y;
        if(i == 0){
            DrawRectangle(x * grid.cell_size+1, y*grid.cell_size+1, grid.cell_size- 1, grid.cell_size- 1, DARKGREEN);  
        } else
            DrawRectangle(x * grid.cell_size+1, y*grid.cell_size+1, grid.cell_size- 1, grid.cell_size- 1, snake_color);
    }
}


void Snake::addSegment(Board grid) {
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


void Snake::get_input(){
    if((IsKeyDown(KEY_RIGHT)) && direction.x != -1 && movement){
        direction = {1,0};
        movement=false;
    }
    if((IsKeyDown(KEY_LEFT)) && direction.x != 1 && movement){
        direction = {-1,0};
        movement=false;
    }
    if((IsKeyDown(KEY_UP)) && direction.y != 1 && movement){
        direction = {0,-1};
        movement=false;
    }
    if((IsKeyDown(KEY_DOWN)) && direction.y != -1 && movement){
        direction = {0,1};
        movement=false;
    }
}


//rand()%(max-min + 1) + min; 
void Snake::draw_apple(Board grid, Color apple_color, Vector2& apple){

    bool apple_snake = true;
    
    if((body_pos[0].x == apple.x) && (body_pos[0].y == apple.y)){
        while(apple_snake == true){
            apple = {(float) (rand() % (grid.boardLong - 2 )+ 1), 
                    (float)(rand() % (grid.boardTall - 2)+ 1)};

            apple_snake = apple_in_snake(apple);
        }
        addSegment(grid);
        score++;
    }  
    DrawRectangle(apple.x * grid.cell_size+1, apple.y*grid.cell_size+1, grid.cell_size- 1, grid.cell_size- 1, apple_color);
}

bool Snake::apple_in_snake(Vector2 apple){
    for(int i = 0; i < body_pos.size(); i++){
        if(Vector2Equals(body_pos[i], apple)){
            return true;
        }
    }
    return false;
}


void Snake::draw_borders(Board grid){
    //top
    DrawRectangle(0, 0, 1920, grid.cell_size, GRAY);
    //bottom
    DrawRectangle(0, 1080 - grid.cell_size , 1920, 1080, GRAY);
    //right
    DrawRectangle(0, 0, grid.cell_size , 1080, GRAY);
    //left
    DrawRectangle(1920 - grid.cell_size, 0, 1920, 1080, GRAY);
}


bool Snake::check_bounds(Board grid){
    if(body_pos[0].x <= 0 || body_pos[0].x >= grid.boardLong - 1 || body_pos[0].y <= 0 || body_pos[0].y >= grid.boardTall - 1){
        return true;
    }
    return false;
}

bool Snake::check_snake_coll(){
    for(int i = 1; i < body_pos.size(); i++){
        if(Vector2Equals(body_pos[0], body_pos[i])){
            return true;
        }
    }
    return false;   
}

