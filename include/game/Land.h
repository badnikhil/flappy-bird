#ifndef LAND_H
#define LAND_h

#include "Game.h"
#include <vector>
class Land{
    public:
    Land(GameDataRef);
    void DrawLand();
    void MoveLand(float dt);
    const std::vector<sf::Sprite> &GetSprites() const;
    private:
    GameDataRef _data;
    std::vector<sf::Sprite> _landSprites;
};


#endif