#-------------------------------------#
# CMake file for Main Pac-Man Game    #
#-------------------------------------#


add_library(PacMan STATIC
    include/pac_man.h
    src/pac_man.cpp
)


target_include_directories(PacMan
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/include
)


target_link_libraries(PacMan
    PRIVATE raylib
)
