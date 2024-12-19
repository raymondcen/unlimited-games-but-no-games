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

    int snakeGame();

    Snake(int, int, int);
    Snake();
    ~Snake();

};
