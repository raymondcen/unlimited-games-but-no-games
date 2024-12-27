/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once



// Custom Libraries
#include "game.h"


class PacMan : public Game {
private:


public:
    PacMan();
    ~PacMan();

    void run_game() override;

};