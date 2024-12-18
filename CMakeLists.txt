cmake_minimum_required(VERSION 3.25)
project(Unlimited-Games-But-Not_Games LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake/Qt6")

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Gui Quick Qml)

add_executable(Unlimited-Games-But-Not_Games src/main.cpp)

target_include_directories(Unlimited-Games-But-Not_Games PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(Unlimited-Games-But-Not_Games PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::Qml)