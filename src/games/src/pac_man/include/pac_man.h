/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once

// Standard Libraries
#include <iostream>
#include <cstdlib>


// Raylib Libraries
#include <raylib.h>
#include <raymath.h>

// Custom Libraries
#include "game.h"
#include "grid.h"
#include "map.h"

typedef enum CurrentScreen { PTITLE = 0, PGAMEPLAY, PEXIT, PPLAY_AGAIN } CurrentScreen;

class PacMan : public Game {
    
private:
    Vector2 position;

    //map variables
    Map map;

    //pac man variables
    Vector2 pac_direction;
    Vector2 pac_pos;
    Vector2 pending_direction;


    //sprites
    Texture2D pac_man_sprite;

    int sprite_scale;

    //spawnpoint
    float pacman_spawn_x = 599;
    float pacman_spawn_y = 497;

    //pacman sprite dimensions
    float pm_width;
    float pm_height;



public:
    PacMan();
    ~PacMan();

    void run_game();
    void draw_pacman();
    void load_sprites();
    void get_input();
    void update_pac();
};