#include "../include/game/Game.h"


Game::Game(int height , int width , std::string title){
    _data -> window.create(sf::VideoMode(width,height) , title , sf::Style::Close | sf::Style::Titlebar);
    run();
}
void Game::run(){
float newTime , frameTime , interpolation;
float currTime = _clock.getElapsedTime().asSeconds();
float accumulator = 0.0f;
while(_data -> window.isOpen()){
    _data->machine.processStateChanges();
    newTime = _clock.getElapsedTime().asSeconds();
    frameTime = newTime - currTime;
    if(frameTime > 0.25f){
        frameTime = 0.25f;
        }
    currTime = newTime;
    accumulator += frameTime;
    while(accumulator > dt){
        _data -> machine.getActiveState()-> handleinput();
        _data -> machine.getActiveState()-> update(dt);
        accumulator -= dt;
        }
    interpolation = accumulator / dt;
    _data -> machine.getActiveState()->draw(interpolation);
    }
}