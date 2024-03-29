# ===========================================
#            Global CMakeLists
# ===========================================
cmake_minimum_required(VERSION 3.27)
project(tetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags to treat warnings as errors
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

# Include subdirectories for source and test
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(documentation)