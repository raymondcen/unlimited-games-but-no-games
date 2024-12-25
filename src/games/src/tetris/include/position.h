/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
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
