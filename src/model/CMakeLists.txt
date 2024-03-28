# ===========================================
#          Sources model CMakeLists
# ===========================================
project(tetris_model)

# C++ sources files of the tetris_model
set(SOURCES
        Position.cpp
        Tetromino.cpp
        Bag.cpp
        Board.cpp
        Game.cpp
)

# Create the model library that public can use
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Include the headers folder for linker
# Note : If needed, we can split headers declaration in multiple child folder in the include folder.
target_include_directories(${PROJECT_NAME} PUBLIC
        ../../include
        # If more folder or more specific you can add it here
)
