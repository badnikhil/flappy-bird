#include <SFML/Graphics.hpp>
#include "stdusages.h"

static sf::Texture upperHalfTxt;
static sf::Texture lowerHalfTxt;
static bool isTxtLoaded;
class Pipe{
    private:
        sf::RectangleShape upperHalf;
        sf::RectangleShape lowerHalf;
        int isPassed = 0;
        float XPos;
    public:
         Pipe(float startX, float gapY, float gapSize, float windowHeight) {
            XPos = startX;
            isPassed = 0;
            const float pipeWidth = 80.0f;
            
            // Upper pipe: from top to gapY
            upperHalf.setSize(sf::Vector2f(pipeWidth, gapY));
            upperHalf.setPosition(startX, 0);
            upperHalf.setTexture(&upperHalfTxt);
            
            // Lower pipe: from (gapY + gapSize) to bottom
            float lowerHeight = windowHeight - (gapY + gapSize);
            lowerHalf.setSize(sf::Vector2f(pipeWidth, lowerHeight));
            lowerHalf.setPosition(startX, gapY + gapSize);
            lowerHalf.setTexture(&lowerHalfTxt);
        }
    
        static void loadPipeTextures() {
        if(isTxtLoaded)return;

        if(!upperHalfTxt.loadFromFile("assets/upper_pipe.png") || !lowerHalfTxt.loadFromFile("assets/lower_pipe.png")){
            print("Couldn't load  pipe textures\n");
        }
        else isTxtLoaded = true;
    }
        void move(float speed) {
        XPos -= speed;
        upperHalf.move(-speed, 0);
        lowerHalf.move(-speed, 0);
        }
        bool isOffScreen() const {
        return XPos < -100;
        }
        bool collideswith(sf::CircleShape &bird){
            return bird.getGlobalBounds().intersects(upperHalf.getGlobalBounds())||
            bird.getGlobalBounds().intersects(lowerHalf.getGlobalBounds());
        }
        void draw(sf::RenderWindow &window){
            window.draw(upperHalf);
            window.draw(lowerHalf);
        }
        int getX(){
            return XPos;
        }

        bool hasPassed(sf::CircleShape &bird){
            if(!isPassed &&  (80 + XPos  < bird.getPosition().x)){
                isPassed = true;
                return true;}
            else return false;
        }
};