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


// grid/board data
struct Board{
    int boardLong;
    int boardTall;
    int cell_size;
    int border;
};

enum GridSize{SMALL, MED, LARGE};


class Snake : public Game{
private:
    std::deque<Vector2> body_pos;
    Vector2 direction;
    bool movement;
    int frames;
    bool out_bounds;
    bool snake_coll;
    int mode;
    int score;
    bool home_screen;
    bool home_screen_drawn;
    bool play;
    Vector2 apple;
    Board grid;
    Grid gridSettings;

    GridSize gridSize;

    //textures
    Texture2D paButton;
    Texture2D exitButton;
    Texture2D title;
    Texture2D largeGrid;
    Texture2D medGrid;
    Texture2D smallGrid;
    Texture2D playButton;
    Texture2D gplayButton;

public:
    Snake();
    ~Snake();
    void run_game() override;

    void draw_snake(Board, Color);
    void draw_apple(Board, Color, Vector2&);
    void addSegment(Board);
    void get_input();
    void move_snake();
    void draw_borders(Board);
    bool check_bounds(Board);
    void end_screen();
    bool check_snake_coll();
    bool apple_in_snake(Vector2);
    void draw_homescreen(Vector2);
    void set_grid();
    void draw_endgame_screen(const char*, const char*, int, int, int);
    void draw_endgame_button(Vector2, Vector2, int, int);
    Vector2 reset_apple(Vector2);
    void set_variables();


};
