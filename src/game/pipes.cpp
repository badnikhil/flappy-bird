#include "../include/game/pipes.h"

// Define static members
sf::Texture Pipe::upperHalfTxt;
sf::Texture Pipe::lowerHalfTxt;
bool Pipe::isTxtLoaded = false;

// Constructor
Pipe::Pipe(float startX, float gapY, float gapSize, float windowHeight) {
    XPos = startX;
    isPassed = 0;
    const float pipeWidth = 80.0f;

    // Upper pipe
    upperHalf.setSize(sf::Vector2f(pipeWidth, gapY));
    upperHalf.setPosition(startX, 0);
    upperHalf.setTexture(&upperHalfTxt);

    // Lower pipe
    float lowerHeight = windowHeight - (gapY + gapSize);
    lowerHalf.setSize(sf::Vector2f(pipeWidth, lowerHeight));
    lowerHalf.setPosition(startX, gapY + gapSize);
    lowerHalf.setTexture(&lowerHalfTxt);
}

// Static method to load textures
void Pipe::loadPipeTextures() {
    if (isTxtLoaded) return;

    if (!upperHalfTxt.loadFromFile("assets/sprites/upper_pipe.png") ||
        !lowerHalfTxt.loadFromFile("assets/sprites/lower_pipe.png")) {
        print("Couldn't load pipe textures\n");
    } else {
        isTxtLoaded = true;
    }
}

// Move pipe
void Pipe::move(float speed) {
    XPos -= speed;
    upperHalf.move(-speed, 0);
    lowerHalf.move(-speed, 0);
}

// Draw pipe
void Pipe::draw(sf::RenderWindow &window) {
    window.draw(upperHalf);
    window.draw(lowerHalf);
}

// Check if pipe is off-screen
bool Pipe::isOffScreen() const {
    return XPos < -100;
}

// Collision detection
bool Pipe::collideswith(sf::CircleShape &bird) {
    return bird.getGlobalBounds().intersects(upperHalf.getGlobalBounds()) ||
           bird.getGlobalBounds().intersects(lowerHalf.getGlobalBounds());
}

// Check if pipe has been passed
bool Pipe::hasPassed(sf::CircleShape &bird) {
    if (!isPassed && (80 + XPos < bird.getPosition().x)) {
        isPassed = true;
        return true;
    }
    return false;
}

// Getter
int Pipe::getX() const {
    return XPos;
}
