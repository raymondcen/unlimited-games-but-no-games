/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/

// Has a run game function the game launcher can call,
// Doesnt need to know what game it is


#pragma once


class Game {
private:
public:
Game();
~Game();

virtual void run_game() = 0;

};
