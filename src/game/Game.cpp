#include "../../include/game/Game.h"
#include "../../include/SplashState/SplashState.h"


Game::Game(int width , int height , std::string title){
    srand(time(NULL));
    _data -> window.create(sf::VideoMode(width,height) , title , sf::Style::Close | sf::Style::Titlebar);
    _data -> machine.addState(StateRef(new SplashState(_data)));
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
        _data -> machine.getActiveState()-> HandleInput();
        _data -> machine.getActiveState()-> Update(dt);
        accumulator -= dt;
        }
    interpolation = accumulator / dt;
    _data -> machine.getActiveState()->Draw(interpolation);
    }
}