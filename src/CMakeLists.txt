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

find_package(Qt6 COMPONENTS Core Widgets QUIET)
if (DEFINED Qt6Widgets_FOUND AND DEFINED Qt6Core_FOUND)
    # Link each sub project to compile the executable
    target_link_libraries(${PROJECT_NAME} PRIVATE
            tetris_controller
            tetris_model
            tetris_view_console
            tetris_tools
            tetris_view_qtApp
    )
    add_compile_definitions(qtAppIsBuilt)
else()
    # Link each sub project to compile the executable
    target_link_libraries(
            ${PROJECT_NAME} PRIVATE
            tetris_controller
            tetris_model
            tetris_view_console
            tetris_tools
    )
endif ()
