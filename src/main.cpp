/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


// Standard Libraries
#include <iostream>
#include <memory>       // For unique ptrs

// Custom Libraries
#include "game_launcher.h"
#include "snake.h"
#include "tetris.h"
#include "pac_man.h"



int main(int argc, char** argv) {
    srand(time(NULL));

    // GameLauncher game_launcher;

    // // Option 1, use vector
    //     // Data gets allocated memory on the heap, vector itself uses an array that is stored on heap, this is a viable option now
    // Snake snake_game;
    // Tetris tetris_game;
    // PacMan pac_man_game;

    // std::vector<Game*> games_stack = {&snake_game, &tetris_game, &pac_man_game};


    // Option 2, allocate games on heap we manually manage
        // Need to find a way to look for memory leaks if we go with this option
    Snake* snake_game_heap = new Snake();
    Tetris* tetris_game_heap = new Tetris();
    PacMan* pac_man_game_heap = new PacMan();

    std::vector<Game*> games_heap = {snake_game_heap, tetris_game_heap, pac_man_game_heap};


    // Option 3, games on heap, but use unique ptrs to manage memory itself
        // Need to learn how this works
    std::unique_ptr<Game> snake_unique = std::make_unique<Snake>();
    std::unique_ptr<Game> tetris_unique = std::make_unique<Tetris>();
    std::unique_ptr<Game> pac_man_unique = std::make_unique<PacMan>();

    std::vector<std::unique_ptr<Game>> games_unique_ptr;
    games_unique_ptr.push_back(std::move(snake_unique));
    games_unique_ptr.push_back(std::move(tetris_unique));
    games_unique_ptr.push_back(std::move(pac_man_unique));

// RUN GAME TO TEST HERE
    games_unique_ptr[0]->run_game();


    // For option 2, we have to manually free
    for (Game* game : games_heap) {
        if (game != nullptr)
            free(game);
    }

    // init launcher
    // add games to launcher
        // have an add game function or pass in games vector?
    // game_launcher.run_launcher();
    // If option 2,
        // On window closing, deallocate memory on heap


    return 0;
}
