# ===========================================
#            Tests CMakeLists
# ===========================================
include(FetchContent)
include(GoogleTest)
project(tetris_test)

# Define test source files
set(TEST_SOURCES
        testMain.cpp
        Bag.cpp
        Board.cpp
        Position.cpp
        Tetromino.cpp
)

# Create the tests main executable
add_executable(${PROJECT_NAME} ${TEST_SOURCES})
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Prevent overriding the parent project's compiler/linker settings for Windows target
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable test in every child directory
enable_testing()

# Link required libraries
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        GTest::gtest
        GTest::gtest_main
        tetris_model
        tetris_tools
)

# Discover tests using Google Test
gtest_discover_tests(${PROJECT_NAME})
