#-------------------------------------#
# CMake file for Flappy Bird Game     #
#-------------------------------------#


add_library(FlappyBird STATIC
    include/flappy_bird.h
    src/flappy_bird.cpp
)


target_include_directories(FlappyBird
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/src/utilities/colors/include
)


target_link_libraries(FlappyBird
    PRIVATE raylib
)
