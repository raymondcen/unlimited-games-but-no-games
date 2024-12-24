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

// Standard Libraries
#include <deque>
#include <ctime>
#include <cstdlib>

// Custom Libraries
#include "grid.h"
#include "game.h"


class Snake : public Game{
private:

std::deque<Vector2> body_pos;
Vector2 direction;
bool movement;

int frames;
bool out_bounds;

int mode;

int score;

public:
Snake();
~Snake();

// grid/board data
struct Board{
    int boardLong;
    int boardTall;
    int cell_size;
    int border;

};


void run_game() override;

void draw_snake(Board, Color);
void draw_apple(Board, Color, Vector2&);
void addSegment(Board);
void get_input();
void move_snake();
void draw_borders(Board);
bool check_bounds(Board);
void end_screen(Texture2D);

};
