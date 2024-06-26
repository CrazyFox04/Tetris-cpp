# ===========================================
#          Qt view app CMakeLists
# ===========================================

# Project declaration for tetris_view_qtApp
project(tetris_view_qtApp)

# C++ source files of the tetris_view
set(SOURCES
        TetrisView.cpp
        BoardBox.cpp
        ColorAnimation.cpp
        InfoBox.cpp
        TetrisQtGUI.cpp
        TetroView.cpp
        nextTetroWidget.cpp
        tetrisConfiguration.cpp
        tetrisGameOver.cpp
)

# Find Qt6 components, suppressing warnings
find_package(Qt6 COMPONENTS Core Widgets QUIET)

# Check if Qt6 components are found
if (DEFINED Qt6Widgets_FOUND AND DEFINED Qt6Core_FOUND)
    # Find required Qt6 components
    find_package(Qt6 COMPONENTS Widgets REQUIRED)

    # Enable Qt automatic handling of UI files, moc files, and resource files
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)

    # Add library target for tetris_view_qtApp
    add_library(${PROJECT_NAME} STATIC ${SOURCES})

    # Link Qt6 libraries to the target
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

    # Include the headers folder for linker
    # Note: If needed, we can split header declarations into multiple child folders in the include folder
    target_include_directories(${PROJECT_NAME} PUBLIC
            ../../../include
            # If more folders or more specific folders are needed, you can add them here
    )

    set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON)

else (DEFINED Qt6Widgets_FOUND AND DEFINED Qt6Core_FOUND)
    # Display a warning if Qt6 components are not found
    message(WARNING "Qt isn't found on your machine. As a result, you can't build tetris Qt App")
endif (DEFINED Qt6Widgets_FOUND AND DEFINED Qt6Core_FOUND)