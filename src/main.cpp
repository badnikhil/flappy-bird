#include <SFML/Graphics.hpp>
#include "screens/gamescreen.h"

int main() {
    
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode :: getDesktopMode()),  "The Game",sf::Style::Fullscreen);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(30);
    renderGameScreen(window);
    int screen = 0;
    return 0;
}