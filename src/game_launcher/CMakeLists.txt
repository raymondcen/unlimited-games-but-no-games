#---------------------------------------#
# CMake file for game launcher library  #
#---------------------------------------#

# Set QML path
set(QML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources/qml")
add_compile_definitions(QML_DIR="${QML_DIR}")

# Files needed for game launcher
add_library(GameLauncher STATIC
    include/game_launcher.h
    src/game_launcher.cpp
)

# Header files
target_include_directories(GameLauncher
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/games/include
)

# Needs Qt
target_link_libraries(GameLauncher
    PUBLIC Qt6::Core Qt6::Gui Qt6::Quick Qt6::Qml
)
