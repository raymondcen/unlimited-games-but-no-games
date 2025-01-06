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

public:
    PacMan();
    ~PacMan();

    void run_game();
    void draw_pacman();

};