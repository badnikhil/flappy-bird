#include "../../include/game/Collision.h"

Collision::Collision(){

}

bool Collision::CheckSpriteCollision(sf::Sprite sprite1 ,float scale1 , sf::Sprite sprite2, float scale2){
    sprite1.scale(scale1 , scale1);
    sprite2.scale(scale2 , scale2);
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();
    return rect1.intersects(rect2);
}