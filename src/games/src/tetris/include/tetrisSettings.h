/****************************************************************************
 * File Name: tetrisSettings.h
 * Date: 7/26/2025
 * Description: Header file for Tetris game settings
 * Dependencies: NA
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/

#pragma once

// Standard libs
#include <stdint.h>
#include <string>

namespace TetrisSettings {
    static const int32_t ScreenWidth = 1280;
    static const int32_t ScreenHeight = 720;
    static const int32_t StartingXPos = 25;
    static const int32_t StartingYPos = 25;
    static const int32_t CellSize = 40;

    static const Color BackgroundColor = {44, 44, 127, 255};
    static const char *TitleImagePath = "../src/games/src/tetris/include/title_image.png";
}
