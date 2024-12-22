/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once


// Standard Libraries
#include <vector>
#include <map>

// Custom Libraries
#include "position.h"


class Block {
private:

int id;
std::map<int, std::vector<Position>> cells;

public:

Block();
~Block();

int get_id();



};
