cmake_minimum_required(VERSION 3.27)
project(OpenGLModelEditor)

set(CMAKE_CXX_STANDARD 20)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always -Wall -g -Wno-deprecated")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/dep/inc)

# Link directories
link_directories(${CMAKE_SOURCE_DIR}/dep/lib)

# Add executable
add_executable(OpenGLModelEditor
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/glad.c
)

# Link libraries
target_link_libraries(OpenGLModelEditor
        ${CMAKE_SOURCE_DIR}/dep/lib/libglfw.3.4.dylib
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
)