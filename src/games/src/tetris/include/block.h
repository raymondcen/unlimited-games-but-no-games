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

// Standard Libraries
#include <vector>
#include <map>

// Custom Libraries
#include "position.h"


// Parent class for blocks
class Block {
protected:

int id;
std::map<int, std::vector<Position>> cells;
int cell_size;
int rotate_state;
Color color;

public:

Block();
Block(Color color);
~Block();

virtual void draw_block() = 0;

};


class L_Block : public Block {
private:

public:

L_Block(Color color);
void draw_block() override;


};
