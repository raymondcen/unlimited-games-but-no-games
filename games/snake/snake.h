/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once


// Raylib Libraries
#include <raylib.h>

// Standard Libraries

// Custom Libraries
#include "game.h"


class Snake : public Game{
private:

int posx;
int posy;
int length;
    
public:

Snake(int, int, int);
Snake();
~Snake();

void run_game();

};
