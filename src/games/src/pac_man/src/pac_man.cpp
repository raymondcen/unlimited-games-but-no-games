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

    // Candidate positions & corresponding hitboxes.
    Vector2 pendingPos = Vector2Add(pac_pos, pending_direction);
    Rectangle pendingHitbox = { pendingPos.x, pendingPos.y, pm_width, pm_height };

    Vector2 forwardPos = Vector2Add(pac_pos, pac_direction);
    Rectangle forwardHitbox = { forwardPos.x, forwardPos.y, pm_width, pm_height };

    // Determine the union area to check for collisions.
    float minX = fmin(pendingHitbox.x, forwardHitbox.x);
    float minY = fmin(pendingHitbox.y, forwardHitbox.y);
    float maxX = fmax(pendingHitbox.x + pendingHitbox.width, forwardHitbox.x + forwardHitbox.width);
    float maxY = fmax(pendingHitbox.y + pendingHitbox.height, forwardHitbox.y + forwardHitbox.height);
    
    // Compute indices of the grid cells to check.
    int startCol = (int) ((minX - map.mid_mapx_get())/map.cellsize_get());
    int endCol   = (int) ((maxX - map.mid_mapx_get())/map.cellsize_get()) + 1;
    int startRow = (int) ((minY - 5)/map.cellsize_get());
    int endRow   = (int) ((maxY - 5)/map.cellsize_get()) + 1;
    
    // Clamp indices to grid boundaries.
    startCol = std::max(0, startCol);
    endCol = std::min(map.numcol_get(), endCol);
    startRow = std::max(0, startRow);
    endRow = std::min(map.numrow_get(), endRow);
    
    bool pendingCollision = false;
    bool forwardCollision = false;
    
    // Check only the nearby cells.
    for (int i = startRow; i < endRow; i++){
        for (int j = startCol; j < endCol; j++){
            if(map.get_cell(i,j) == 1){
                Rectangle wallRect = {
                    j * map.cellsize_get() + map.mid_mapx_get(), 
                    i * map.cellsize_get() + 5,
                    map.cellsize_get(),
                    map.cellsize_get()
                };
                if(CheckCollisionRecs(pendingHitbox, wallRect)){
                    pendingCollision = true;
                }
                if(CheckCollisionRecs(forwardHitbox, wallRect)){
                    forwardCollision = true;
                }
                // Early exit if both collisions have been determined.
                if(pendingCollision && forwardCollision) break;
            }
        }
        if(pendingCollision && forwardCollision) break;
    }
    
    // If no collision for the pending move, update direction.
    if(!pendingCollision){
        pac_direction = pending_direction;
        // Update the forward hitbox after applying new direction.
        forwardPos = Vector2Add(pac_pos, pac_direction);
        forwardHitbox = { forwardPos.x, forwardPos.y, pm_width, pm_height };
    }
    
    // Update pac position only if there's no collision in the forward move.
    if(!forwardCollision){
        pac_pos = forwardPos;
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


