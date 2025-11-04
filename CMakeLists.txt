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
    src/InputManager/InputManager.cpp
    src/asset/AssetManager.cpp
    src/game/Game.cpp
    src/state/StateMachine.cpp
    src/SplashState/SplashState.cpp
    src/screens/MainMenuState.cpp
    src/screens/GameState.cpp
    src/screens/GameOverState.cpp
    src/game/Pipe.cpp
    src/game/Land.cpp
    src/game/Bird.cpp
)

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} 
    sfml-graphics 
    sfml-window 
    sfml-system
)
