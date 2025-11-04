#include "../../include/InputManager/InputManager.h"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button , sf::RenderWindow &window){
    if(sf::Mouse::isButtonPressed(button)){
        sf::Vector2f Position = object.getPosition();
        sf::IntRect temp(Position.x , Position.y , object.getGlobalBounds().width , object.getGlobalBounds().height);
        if(temp.contains(sf::Mouse::getPosition(window)))return true;
    }
    return false;
}

sf::Vector2i InputManager::GetMousePosition(sf:: RenderWindow window){
    return sf::Mouse::getPosition(window);
}