#-------------------------------------#
# CMake file for Tetris library        #
#-------------------------------------#


add_library(Tetris STATIC
    include/tetris.h
    src/tetris.cpp
)


target_include_directories(Tetris
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/src/grid_board/include
)


target_link_libraries(Tetris
    PRIVATE raylib
    PRIVATE GridBoard
)
