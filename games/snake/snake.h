/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once


#include "game.h"


class Snake {
private:

int posx;
int posy;
int length;
    
public:

Snake(int xpos, int ypos, int len);
~Snake();
int snakeGame();

};
