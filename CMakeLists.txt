cmake_minimum_required(VERSION 3.31)
project(Unlimited-Games-But-Not_Games VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt path
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake/Qt6")

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Gui Quick Qml)

set(CMAKE_AUTOMOC ON)

# qt_wrap_cpp(MOC_SOURCES include/game_launcher.h)

include(FetchContent)

# Fetch raylib library from GitHub
FetchContent_Declare (
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 4.5.0
)

FetchContent_MakeAvailable(raylib)

qt_standard_project_setup()

# Cpp files to be compiled
add_executable(Unlimited-Games-But-Not_Games
    src/main.cpp 
    games/snake/snake.cpp
)

# Header files needed
target_include_directories(Unlimited-Games-But-Not_Games 
    PRIVATE raylib ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${PROJECT_SOURCE_DIR}/games/snake
    #PRIVATE ${PROJECT_SOURCE_DIR}/games/tetris
)

# Libraries needed
target_link_libraries(Unlimited-Games-But-Not_Games 
    PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::Qml
    PRIVATE raylib
)
