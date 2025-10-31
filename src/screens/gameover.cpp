#include "../include/screens/gameover.h"

void gameOverScreen(sf::RenderWindow &window){
    sf::RectangleShape blackBG(sf::Vector2f(window.getSize().x , window.getSize().y));
    blackBG.setFillColor(sf::Color(200, 200, 200));
    bool screenChanged = 0;
    while(!screenChanged){
        window.draw(blackBG);
        window.display();
    }
}