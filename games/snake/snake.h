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
#include <raymath.h>
#include <deque>
// Standard Libraries

// Custom Libraries
#include "game.h"
#include "grid.h"


class Snake : public Game{
private:

std::deque<Vector2> body_pos;
Vector2 direction;
int length;

public:
Snake();
~Snake();

void run_game();


void draw_snake(int, Color);

void updateSnake();

};
