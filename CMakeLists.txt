cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(space_invader VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(space_invader main.cpp)

cmake_policy(SET CMP0072 NEW)

# Find the GLFW package
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

# Link the GLFW library to your executable
target_link_libraries(space_invader glfw OpenGL::GL)
