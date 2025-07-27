/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/

#pragma once

#include <string>

class Game {
private:
    std::string title;
    std::string description;

public:
    Game();
    ~Game();
    virtual void run_game() = 0;

};
