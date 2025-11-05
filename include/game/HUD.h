#ifndef HUD_H
#define HUD_H

#include "Game.h"
class HUD{
    public:
        HUD(GameDataRef data);
        ~HUD();
        void Draw();
        void UpdateScore(int score);
    private:
        GameDataRef _data;
        sf::Text _scoreText;

};

#endif