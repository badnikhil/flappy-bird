cmake_minimum_required(VERSION 3.10)
project(FlappyBird)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SFML_INCLUDE_DIR}
)

# Add executable
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/screens/gamescreen.cpp
    src/screens/gameover.cpp
    src/game/pipes.cpp
    src/utils/save_score.cpp
    src/utils/stdusages.cpp
)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} 
    sfml-graphics 
    sfml-window 
    sfml-system
)
