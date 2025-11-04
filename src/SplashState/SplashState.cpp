#include "../../include/SplashState/SplashState.h"
#include "../../include/DEFINITIONS.h"
#include "../../include/screens/MainMenuState.h"

SplashState:: SplashState(GameDataRef data) : _data(data){
    
}
void SplashState::Init(){
    
}
void SplashState::HandleInput(){
    sf::Event event;
    while(_data -> window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
        _data->window.close();
        }
    }
}
void SplashState::Update(float dt){
    if(_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_SHOW_TIME){
        _data->machine.addState(StateRef(new MainMenuState(_data)), false);
    }
}
void SplashState::Draw(float dt){
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
}


void SplashState::Pause(){

}
void SplashState::Resume(){

}
