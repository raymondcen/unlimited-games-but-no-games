#-------------------------------------#
# CMake file for Snake library        #
#-------------------------------------#


add_library(Snake STATIC
    include/snake.h
    src/snake.cpp
)


target_include_directories(Snake
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/src/utilities/colors/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/src/utilities/grid_board/include
)


target_link_libraries(Snake
    PRIVATE raylib
    PRIVATE GridBoard
)
