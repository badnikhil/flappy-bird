#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include "../utils/stdusages.h"

class Pipe {
private:
    sf::RectangleShape upperHalf;
    sf::RectangleShape lowerHalf;
    static sf::Texture upperHalfTxt;
    static sf::Texture lowerHalfTxt;
    static bool isTxtLoaded;

    int isPassed;
    float XPos;

public:
    // Constructor
    Pipe(float startX, float gapY, float gapSize, float windowHeight);

    // Static function to load textures
    static void loadPipeTextures();

    // Movement and rendering
    void move(float speed);
    void draw(sf::RenderWindow &window);

    // Collision and state checks
    bool isOffScreen() const;
    bool collideswith(sf::CircleShape &bird);
    bool hasPassed(sf::CircleShape &bird);

    // Getter
    int getX() const;
};

#endif
