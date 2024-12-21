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
#include <ctime>
#include <cstdlib>
// Standard Libraries

// Custom Libraries
#include "game.h"
#include "grid.h"


class Snake : public Game{
private:

std::deque<Vector2> body_pos;
Vector2 direction;
bool movement;

public:
Snake();
~Snake();

// grid/board data
struct Board{
    int boardLong;
    int boardTall;
    int cell_size;
};


void run_game();

void draw_snake(Board, Color);
void draw_apple(Board, Color, Vector2&);
void addSegment(Board);
void move_snake();
void updateSnake();

};
