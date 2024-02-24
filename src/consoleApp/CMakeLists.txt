cmake_minimum_required(VERSION 3.28)
project(testCmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")
set(SOURCES
        main.cpp
)
set(HEADERS
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})