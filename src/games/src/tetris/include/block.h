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
#include "settings.h"


// Parent class for blocks
class Block {
protected:
    int id;
    std::map<int, std::vector<Position>> cells;
    int cell_size;
    int rotate_state;
    Color color;
    int row_offset;
    int column_offset;

public:
    Block();
    ~Block();
    void move_block(int rows, int columns);
    std::vector<Position> get_cell_positions();
    void draw_block();

};


class L_Block : public Block {
public:
    L_Block(Color color);

};


class J_Block : public Block {
public:
    J_Block(Color color);

};


class I_Block : public Block {
public:
    I_Block(Color color);

};

class O_Block : public Block {
public:
    O_Block(Color color);

};


class S_Block : public Block {
public:
    S_Block(Color color);

};


class Z_Block : public Block {
public:
    Z_Block(Color color);

};


class T_Block : public Block {
public:
    T_Block(Color color);

};
