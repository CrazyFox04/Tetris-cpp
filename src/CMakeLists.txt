# ===========================================
#            Sources CMakeLists
# ===========================================
project(tetris)

# Include subdirectory for model
add_subdirectory(model)
add_subdirectory(command)
add_subdirectory(view)

# Create the main executable
add_executable(${PROJECT_NAME} main.cpp)

# Link each sub project to compile the executable
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        tetris_model
        tetris_command
        tetris_view
)