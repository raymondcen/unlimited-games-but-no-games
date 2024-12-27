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
#include "colors.h"


// Parent class for blocks
class Block {
protected:
    int id;
    std::map<int, std::vector<Position>> cells;
    int cell_size;
    int rotate_state;
    int row_offset;
    int column_offset;

public:
    Block();
    ~Block();
    int get_id() const;
    void move_block(int rows, int columns);
    std::vector<Position> get_cell_positions();
    void update_rotate_state(int rotates);
    void draw_block(int x_offset, int y_offset);

};


class L_Block : public Block {
public:
    L_Block();

};


class J_Block : public Block {
public:
    J_Block();

};


class I_Block : public Block {
public:
    I_Block();

};

class O_Block : public Block {
public:
    O_Block();

};


class S_Block : public Block {
public:
    S_Block();

};


class Z_Block : public Block {
public:
    Z_Block();

};


class T_Block : public Block {
public:
    T_Block();

};
