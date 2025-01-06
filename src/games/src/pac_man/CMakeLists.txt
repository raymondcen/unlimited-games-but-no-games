#-------------------------------------#
# CMake file for Main Pac-Man Game    #
#-------------------------------------#


add_library(PacMan STATIC
    include/ghost.h
    include/pac_man.h
    include/map.h
    assets
    src/pac_man.cpp
    src/ghost.cpp
    src/map.cpp
)


target_include_directories(PacMan
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/src/utilities/colors/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/src/utilities/grid_board/include
)


target_link_libraries(PacMan
    PRIVATE raylib
)
