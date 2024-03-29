# ===========================================
#            Sources CMakeLists
# ===========================================
project(tetris)

# Include subdirectory for model
add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(tools)

# Create the main executable
add_executable(${PROJECT_NAME} main.cpp
        controller/Invoker.cpp
        controller/MoveDownCommand.cpp
        controller/MoveLeftCommand.cpp
        controller/MoveRightCommand.cpp
        controller/RotateClockwiseCommand.cpp
        controller/RotateCounterClockwise.cpp
        controller/DropCommand.cpp)

# Link each sub project to compile the executable
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        tetris_model
        tetris_view
        tetris_tools
)