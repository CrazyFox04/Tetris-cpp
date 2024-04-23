# ===========================================
#            Sources CMakeLists
# ===========================================
project(tetris)

# Include subdirectory for model
add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(tools)
add_subdirectory(controller)

# Create the main executable
add_executable(${PROJECT_NAME} main.cpp)

# Link each sub project to compile the executable
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        tetris_controller
        tetris_model
        tetris_view_console
        tetris_view_qtApp
        tetris_tools
)