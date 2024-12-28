/****************************************************************************
 * File Name: position.h
 * Date: 12/27/2024
 * Description: Header file for Position class
 * Dependencies: None
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#pragma once


class Position {
private:
    int row;
    int column;

public:
    Position(int row, int column);
    ~Position();
    int get_row() const;
    int get_column() const;

};
