#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../utils/stdusages.h"
#include "../game/pipes.h"
#include "gameover.h"
#include "../utils/save_score.h"

int renderGameScreen(sf::RenderWindow &window);

#endif
