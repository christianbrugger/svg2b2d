cmake_minimum_required(VERSION 3.6)

project(svg2b2d CXX)

add_library(svg2b2d STATIC
	src/svg.cpp
)
target_include_directories(svg2b2d PUBLIC
	src/
)
target_link_libraries(svg2b2d PUBLIC 
    Blend2D::Blend2D
)
