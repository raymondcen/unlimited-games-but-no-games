#-------------------------------------#
# CMake file for Colors library       #
#-------------------------------------#


add_library(Colors STATIC
    include/colors.h
    src/colors.cpp
)


target_include_directories(Colors
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)


target_link_libraries(Colors
    PRIVATE raylib
)
