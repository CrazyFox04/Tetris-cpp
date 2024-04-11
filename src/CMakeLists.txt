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
        tetris_tools
)

# Link Qt View App library to compile the executable only if found
if (DEFINED Qt6Widgets_FOUND AND DEFINED Qt6Core_FOUND)
    target_link_libraries(
            ${PROJECT_NAME} PRIVATE tetris_view_qtApp
    )
endif ()