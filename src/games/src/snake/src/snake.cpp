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

    home_screen = true; 
    home_screen_drawn = false;
    play = false;
}

Snake::~Snake() {}


void Snake::run_game() {
    //stop debug terminal
    SetTraceLogLevel(LOG_ERROR);

    //resolution
    const int screenWidth = 1920;
    const int screenHeight = 1080;
 
    //resize window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Ekans");

    //load images
    paButton = LoadTexture("../src/games/src/snake/include/paButton.png");
    exitButton = LoadTexture("../src/games/src/snake/include/exitButton.png");
    title = LoadTexture("../src/games/src/snake/include/title.png");
    largeGrid = LoadTexture("../src/games/src/snake/include/largeGrid.png");
    medGrid = LoadTexture("../src/games/src/snake/include/medGrid.png");
    smallGrid = LoadTexture("../src/games/src/snake/include/smallGrid.png");
    playButton = LoadTexture("../src/games/src/snake/include/playButton.png");
    gplayButton = LoadTexture("../src/games/src/snake/include/gplayButton.png");


    // Comment out for now b/c theres no exit button
    // ToggleFullscreen();


    //snake variables
    Color snake_color = GREEN;


    //apple variaables
    Color apple_color = RED;
    apple = {(float) (rand() % (grid.boardLong - 2 )+ 1), (float)(rand() % (grid.boardTall - 2)+ 1)}; //random position of apple


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
    int per_sec = 7;


    // Main game loop
    while (!WindowShouldClose())                                                                // Detect window close button or ESC key
    {   
        get_input();

        //move every x frames
        if(frames%per_sec == 0 && home_screen == false){
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

            if(out_bounds == true || snake_coll == true){                                           //end game screen
                
                draw_endgame_screen(playAgainText, scoreText, score, paWid, sWid);
                draw_endgame_button(paPos, exitPos, paScale, exitScale);
                mousePoint = GetMousePosition();

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
 
            } else if(out_bounds == false && snake_coll == false && home_screen == false){          //regular game
                ClearBackground(GRAY);
                 //draw grid  
                gridSettings.draw_grid(0, 0);
                draw_borders(grid);

                //draw snake
                draw_snake(grid, snake_color);

                //draw apple
                draw_apple(grid, apple_color, apple);

            } else if(home_screen == true){                                                         //home screen
                draw_homescreen(mousePoint);
                set_grid();
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


void Snake::draw_endgame_screen(const char* playAgainText, const char* scoreText, int score, int paWid, int sWid){
    //draw base 
    DrawRectangle(480, 100, 960, 880, DARKGRAY); //border of base
    DrawRectangle(500, 120, 920, 840, DARKGREEN); //inner base
    
    //DrawText(const char *text, int posX, int posY, int fontSize, Color color); 
    //draw play again and score TEXT
    DrawText(playAgainText, (GetScreenWidth() - paWid)/2, 180, 120, BLACK);
    DrawText(TextFormat(scoreText, score), (GetScreenWidth() - sWid)/2, 420, 100, GREEN);
}

void Snake::draw_endgame_button(Vector2 paPos, Vector2 exitPos, int paScale, int exitScale){
    //DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);    
    //draw play again and exit BUTTON
    DrawTextureEx(paButton, paPos, 0.0f, (float)paScale, WHITE);
    DrawTextureEx(exitButton, exitPos, (float)0, (float)exitScale, WHITE);

}


void Snake::draw_homescreen(Vector2 mousePoint){ 
    ClearBackground(LIME);
    //DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);    

    //title
    DrawTextureEx(title, {(float)(GetScreenWidth() - (title.width*8))/2, 90.0f}, 0, 8, WHITE);

    const char *sizeText = "SELECT A GRID SIZE";
    int sizeTWid = MeasureText(sizeText, 40);
    DrawText(sizeText, (GetScreenWidth() - sizeTWid)/2, 350, 40, BLACK);

    float x = (((GetScreenWidth() - (medGrid.width*10))/2) - ((GetScreenWidth() - (smallGrid.width*10))/3)) + (1920/2);
    float medy = ((largeGrid.height*10 - medGrid.height*10)/2)+425;
    float smally = ((largeGrid.height*10 - smallGrid.height*10)/2)+425;

    //grid sizes
    DrawTextureEx(smallGrid, {(float)(GetScreenWidth() - (smallGrid.width*10))/3, smally}, 0, 10, WHITE);
    DrawTextureEx(medGrid, {(float)(GetScreenWidth() - (medGrid.width*10))/2, medy}, 0, 10, WHITE);
    DrawTextureEx(largeGrid, {x, 425.0f}, 0, 10, WHITE);
    //play button

    //greyed out play button
    DrawTextureEx(gplayButton, {(float)(GetScreenWidth() - (gplayButton.width*6))/2, 670.0f}, 0, 6, WHITE);
    //exit button
    DrawTextureEx(exitButton, {(float)(GetScreenWidth() - (exitButton.width*6))/2, 770.0f}, 0, 6, WHITE);
    home_screen_drawn = true;

    mousePoint = GetMousePosition();
    Rectangle smallRec = {(float)(GetScreenWidth() - (smallGrid.width*10))/3, (float)((largeGrid.height*10 - smallGrid.height*10)/2)+425, (float)smallGrid.width*10, (float)smallGrid.height*10};


    // if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, smallRec)) {

    //     DrawRectangle(smallRec.x, smallRec.y, smallRec.width, smallRec.height, DARKGREEN);
    //     DrawTextureEx(smallGrid, {(float)(GetScreenWidth() - (smallGrid.width*10))/3, smally}, 0, 10, WHITE);
    // }
    
    //select grid, hit play. call set_grid(), 

    //hit play w/o selecting grid, greyed out play button.

}


void Snake:: set_grid(){

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
    gridSettings = Grid(grid.boardTall, grid.boardLong, grid.cell_size);

}
