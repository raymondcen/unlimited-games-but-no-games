/****************************************************************************
 * File Name:
 * Date: 1/7/2025
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


// Standard Libraries


// Raylib Libraries
#include <raylib.h>


// Custom Libraries
#include "game.h"


class FlappyBird : public Game {
private:

public:
    FlappyBird();
    ~FlappyBird();
    void run_game() override;

};
