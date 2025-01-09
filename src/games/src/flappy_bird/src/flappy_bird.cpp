/****************************************************************************
 * File Name:
 * Date: 1/7/2025
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "flappy_bird.h"


/*
    Game requirements:
    Main Menu/ Start game page
    Play Again page
    Bird movement
        Jump up on space pressed
    Pipe generation
        Have to be possible for bird to go through
    Score system
        Current score
        High Score
    Pipe moving
    Background moving
*/


FlappyBird::FlappyBird() {}


FlappyBird::~FlappyBird() {}


void FlappyBird::setup_game() {}


void FlappyBird::run_game() {
    InitWindow(SCREEN_WIDTH_FB, SCREEN_HEIGHT_FB, "DRIB YPPALF");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }
    CloseWindow();

    return;
}
