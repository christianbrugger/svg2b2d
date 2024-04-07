# Dependencies:
#
# 1) Blend2d v0.10 or newer
#    We assume that Blend2D is provided in some manner by the calling context
#
cmake_minimum_required(VERSION 3.6)

project(svg2b2d CXX)

# Library
add_library(svg2b2d STATIC
	src/svg.cpp
)
target_include_directories(svg2b2d PUBLIC
	src/
)
target_link_libraries(svg2b2d PUBLIC 
    Blend2D::Blend2D
)

# Gen-Image Executable
add_executable(svg2b2d_genimage
	projects/genimage/svg2png.cpp
)
target_link_libraries(svg2b2d_genimage PRIVATE
	svg2b2d
)
target_include_directories(svg2b2d_genimage PRIVATE
	projects/
)

# Pull-XML Executable
add_executable(svg2b2d_pullxml
	projects/pullxml/pullxml.cpp
)
target_link_libraries(svg2b2d_pullxml PRIVATE
	svg2b2d
)
target_include_directories(svg2b2d_pullxml PRIVATE
	projects/
)
