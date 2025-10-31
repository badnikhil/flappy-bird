#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stdusages.h"
#include "pipes.cpp"
#include "gameover.h"
#include "save_score.h"
const float gravity = 1;
float birdVelocityY = 0;
const float jumpStrength = -10;
const float SCROLL_SPEED = 10.0f;
const float GAP_SIZE = 300.0f;

int renderGameScreen(sf::RenderWindow &window){
    srand(time(0));
    
    sf::Vector2i mouseCords = sf::Mouse::getPosition(window);
    sf::CircleShape bird(50.f);
    sf::RectangleShape background(sf::Vector2f(window.getSize()));
    sf::RectangleShape backgroundAlt(sf::Vector2f(window.getSize()));
    sf::RectangleShape customcursor(sf::Vector2f(50,50));
    bool  stopped = 0;
    sf::Image icon;
    sf::Texture cursorImg;
    sf::Cursor cursor;
    sf::Text txt;
    sf::Font font;

    if(!font.loadFromFile("fonts/roboto.ttf")){
        print("Failed to load Font\n");
    }
    if (!icon.loadFromFile("assets/favicon.png")) {
        print("Failed to load icon!\n");
        return -1;
    }
    if(!cursorImg.loadFromFile("assets/cursor.png")){
        print("Failed to load cursor!\n");
        return -1;
    }
    
    customcursor.setTexture(&cursorImg);
    txt.setFont(font);
    txt.setCharacterSize(48);
    txt.setFillColor(sf::Color::White);
    txt.setOutlineColor(sf::Color::Black);
    txt.setOutlineThickness(2.0f);
    txt.setString("Score: " + std::to_string(1));
    sf::FloatRect textBounds = txt.getLocalBounds();
    txt.setPosition((window.getSize().x - textBounds.width) / 2.0f, 20);
 
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    sf::Texture birdtx;
    if(!birdtx.loadFromFile("assets/bluebird-downflap.png")){
        print("Error loading bird texture\n");
    }
    
    sf::Texture bgtx;
    customcursor.setOrigin(customcursor.getSize().x / 2, customcursor.getSize().y / 2);

    if(!bgtx.loadFromFile("assets/background-day.png")){
        print("Failed to load Background Texture\n");
        return -1;
    }
    
    backgroundAlt.setTexture(&bgtx);
    
    // Load pipe textures
    Pipe::loadPipeTextures();
    
    background.setTexture(&bgtx);
    bird.setTexture(&birdtx);
    
    bird.setPosition(400, 300);
    background.setPosition(0, 0);
    backgroundAlt.setPosition(window.getSize().x, 0);
    
    int score = 0;
    
    // Pipe setup
    std::vector<Pipe> pipes;
    float pipeSpawnTimer = 0;
    float pipeSpawnInterval = 90.0f; 
    
    int bestScore = loadHighScore(); 

    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(32);
    highScoreText.setFillColor(sf::Color::Yellow);
    highScoreText.setOutlineColor(sf::Color::Black);
    highScoreText.setOutlineThickness(1.5f);
    highScoreText.setString("High Score: " + std::to_string(bestScore));
    highScoreText.setPosition(20, 20);
    while(window.isOpen()){
        // pipes
        pipeSpawnTimer++;
        if(pipeSpawnTimer >= pipeSpawnInterval) {
            pipeSpawnTimer = 0;
            
            // Random gap Y position
            float minGapY = 150.0f;
            float maxGapY = window.getSize().y - GAP_SIZE - 150.0f;
            float randomGapY = minGapY + (rand() % static_cast<int>(maxGapY - minGapY));
            
            // Spawn new pipe at right edge of screen
            pipes.push_back(Pipe(window.getSize().x, randomGapY, GAP_SIZE, window.getSize().y));
            std::cout << "Spawned pipe at gap Y: " << randomGapY << std::endl;
        }
        
        // bird physics
        bird.move(0, birdVelocityY);
        birdVelocityY += gravity;
        if(birdVelocityY > 15.0f) {
            birdVelocityY = 15.0f;
        }
        
        // Move all pipes
        for(auto& pipe : pipes) {
            pipe.move(SCROLL_SPEED);
        
        }
        
        // Remove off-screen pipes
        for(int i = pipes.size() - 1; i >= 0; i--) {
            if(pipes[i].isOffScreen()) {
                pipes.erase(pipes.begin() + i);
                std::cout << "Removed pipe. Total pipes: " << pipes.size() << std::endl;
            }
        }
        
        // Check collisions
        for(auto& pipe : pipes) {
            if(pipe.collideswith(bird)) {
                std::cout << "COLLISION! Game Over!" << std::endl;
                bird.setPosition(400, 300);
                birdVelocityY = 0;
                pipes.clear(); // Clear all pipes on collision
                pipeSpawnTimer = 0; 
                if(score > bestScore){saveHighScore(score);bestScore = score;}
                score = 0;
                txt.setString("Score: " + std::to_string(score));
                stopped = 1;
                highScoreText.setString("High Score: " + std::to_string(bestScore));
                // gameOverScreen(window);
            }
            
            if(pipe.hasPassed(bird)) {
                score++;
                txt.setString("Score: " + std::to_string(score));
            }
        }
        
        // Check if bird hits top or bottom
        if(bird.getPosition().y <= 0 || bird.getPosition().y >= window.getSize().y - 100) {
            std::cout << "Hit boundary! Game Over!" << std::endl;
            bird.setPosition(400, 300);
            birdVelocityY = 0;
            pipes.clear();
            pipeSpawnTimer = 0;
            if(score > bestScore){saveHighScore(score);bestScore = score;}
            highScoreText.setString("High Score: " + std::to_string(bestScore));
            score = 0;
            txt.setString("Score: " + std::to_string(score));
            stopped = 1;
        }
        
        sf::Vector2i mouseCords = sf::Mouse::getPosition(window);
        customcursor.setPosition(mouseCords.x, mouseCords.y);
        sf::Event event;
        
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) 
                window.close();
                
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.control && event.key.code == sf::Keyboard::R){
                    bird.setPosition(400, 300);
                    birdVelocityY = 0;
                    pipes.clear();
                    pipeSpawnTimer = 0;
                }
                if(event.key.code == sf::Keyboard::Space){
                    birdVelocityY = jumpStrength;
                }
            }
        }
        
        //  moving background
        if(!stopped){
        background.move(-SCROLL_SPEED, 0);
        backgroundAlt.move(-SCROLL_SPEED, 0);\
        if(background.getPosition().x <= -static_cast<float>(window.getSize().x)) {
            background.setPosition(backgroundAlt.getPosition().x + static_cast<float>(window.getSize().x), 0);
        }
        
        if(backgroundAlt.getPosition().x <= -static_cast<float>(window.getSize().x)) {
            backgroundAlt.setPosition(background.getPosition().x + static_cast<float>(window.getSize().x), 0);
        }
        }
        
         
        window.draw(background);
        window.draw(backgroundAlt);
        
        // Draw all pipes
        for(auto& pipe : pipes) {
            pipe.draw(window);
        }
        
        window.draw(bird);
        window.draw(txt);
        window.draw(customcursor);
        window.draw(highScoreText);
        window.display();
        window.clear();
    }
    
    return 0;
}