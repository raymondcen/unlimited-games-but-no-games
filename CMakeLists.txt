#-------------------------------------#
# CMake file for Main app project     #
#-------------------------------------#


cmake_minimum_required(VERSION 3.25)
project(UnlimitedGames VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Find Qt
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake/Qt6")
find_package(Qt6 6.8 REQUIRED COMPONENTS Core Gui Quick Qml)
set(CMAKE_AUTOMOC ON)

include(FetchContent)

# Fetch raylib library from GitHub
FetchContent_Declare (
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

qt_standard_project_setup()


# Utility libraries
add_subdirectory(src/games/src/grid_board)

# Main libraries
add_subdirectory(src/game_launcher)
add_subdirectory(src/games/src/snake)


# Files to be compiled
add_executable(UnlimitedGames
    src/games/src/game.cpp
    src/main.cpp
)


# Header files needed
target_include_directories(UnlimitedGames
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/game_launcher/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/games/src/snake/include
)


# Libraries needed
target_link_libraries(UnlimitedGames
    PRIVATE raylib
    PRIVATE GameLauncher
    PRIVATE Snake
)
