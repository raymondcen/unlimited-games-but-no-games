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
    pac_pos =  {pacman_spawn_x, pacman_spawn_y};

    sprite_scale = 2;
}


PacMan::~PacMan() {}



void PacMan::draw_pacman(){
    //DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);  
    DrawRectangle(pac_pos.x, pac_pos.y, pm_width, pm_height, GREEN);
    Rectangle pm_hitbox {pac_pos.x, pac_pos.y, pm_width, pm_height};

    DrawTextureEx(pac_man_sprite, pac_pos, 0, sprite_scale, WHITE);    
}

void PacMan::load_sprites(){
    pac_man_sprite = LoadTexture("../src/games/src/pac_man/assets/pactest.png");
    pm_width = pac_man_sprite.width*sprite_scale+3;
    pm_height = pac_man_sprite.height*sprite_scale+3;
}


void PacMan::get_input(){
    if((IsKeyDown(KEY_RIGHT))){
        pending_direction = {1,0};
    }
    if((IsKeyDown(KEY_LEFT))){
        pending_direction = {-1,0};
    }
    if((IsKeyDown(KEY_UP))){
        pending_direction = {0,-1};
    }
    if((IsKeyDown(KEY_DOWN))){
        pending_direction = {0,1};
    }
}


void PacMan::update_pac(){
    // TODO: FIND MORE EFFICIENT WAY TO DETECT COLLISION
    get_input();
    
    // Check if the pending direction can be applied.
    Vector2 potentialPos = Vector2Add(pac_pos, pending_direction);
    Rectangle potentialHitbox = { potentialPos.x, potentialPos.y, pm_width, pm_height };
    bool turnPossible = true;

    // Iterate over the map grid for potential turn collision.
    for (int i = 0; i < map.numrow_get(); i++){
        for (int j = 0; j < map.numcol_get(); j++){
            if(map.get_cell(i, j) == 1){
                Rectangle wallRect = {
                    j * map.cellsize_get() + map.mid_mapx_get(), 
                    i * map.cellsize_get() + 5,
                    map.cellsize_get(),
                    map.cellsize_get()
                };

                if(CheckCollisionRecs(potentialHitbox, wallRect)){
                    turnPossible = false;
                    break;
                }
            }
        }
        if(!turnPossible) break;
    }
    
    // If the turn is available, update the current direction.
    if(turnPossible){
        pac_direction = pending_direction;
    }
    
    // Calculate the new position based on the current pac_direction.
    Vector2 newPos = Vector2Add(pac_pos, pac_direction);
    Rectangle newHitbox = { newPos.x, newPos.y, pm_width, pm_height };
    bool collision = false;

    // Check collision for new position.
    for (int i = 0; i < map.numrow_get(); i++){
        for (int j = 0; j < map.numcol_get(); j++){
            if(map.get_cell(i, j) == 1){
                Rectangle wallRect = {
                    j * map.cellsize_get() + map.mid_mapx_get(), 
                    i * map.cellsize_get() + 5,
                    map.cellsize_get(),
                    map.cellsize_get()
                };

                if(CheckCollisionRecs(newHitbox, wallRect)){
                    collision = true;
                    break;
                }
            }
        }
        if(collision) break;
    }

    // Update pac position only if there's no collision.
    if(!collision){
        pac_pos = newPos;
    }
}

void PacMan::run_game() {

    InitWindow(sw, sh, "NAM-CAP");
    SetTargetFPS(80);
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


