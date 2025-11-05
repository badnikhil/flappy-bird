#ifndef FLASH_H
#define FLASH_H

#include "Game.h"
#include <SFML/Graphics.hpp>


class Flash{
    public:
        Flash(GameDataRef data);
        void Show(float dt);
        void Draw();
    private:
        GameDataRef _data;
        sf::RectangleShape _shape;
        bool _flashOn;

};



#endif