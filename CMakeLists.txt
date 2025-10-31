cmake_minimum_required(VERSION 3.10)
project(SFMLApp)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(SFMLApp main.cpp gamescreen.cpp pipes.cpp stdusages.cpp gameover.cpp save_score.cpp)


target_link_libraries(SFMLApp sfml-graphics sfml-window sfml-system)
