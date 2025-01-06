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
    pac_direction =  {0,0};
    pac_pos =  {sw/2, sh/2};


}


PacMan::~PacMan() {}



void PacMan::draw_pacman(){
    //DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);    
    DrawTextureEx(pac_man_sprite, pac_pos, 0, 2, WHITE);    
}

void PacMan::load_sprites(){
    pac_man_sprite = LoadTexture("../src/games/src/pac_man/assets/pactest.png");
}


void PacMan::get_input(){
    if((IsKeyDown(KEY_RIGHT))){
        pac_direction = {1,0};
    }
    if((IsKeyDown(KEY_LEFT))){
        pac_direction = {-1,0};
    }
    if((IsKeyDown(KEY_UP))){
        pac_direction = {0,-1};
    }
    if((IsKeyDown(KEY_DOWN))){
        pac_direction = {0,1};
    }
}


void PacMan::update_pac(){
    get_input();
    pac_pos = Vector2Add(pac_pos, pac_direction); //move pacman
}

void PacMan::run_game() {

    InitWindow(sw, sh, "NAM-CAP");
    SetTargetFPS(60);
    //ToggleFullscreen();

    map.initiate_map();

    load_sprites();

    while (!WindowShouldClose()) {
        update_pac();

        
        BeginDrawing();
            ClearBackground(BLACK);
            
            map.draw_map(0,0);

            draw_pacman();

        EndDrawing();
    }

    CloseWindow();
}


