#include "../../include/screens/GameOverState.h"
#include "../../include/DEFINITIONS.h"
#include "../../include/screens/GameState.h"
#include "../../include/screens/MainMenuState.h"

GameOverState:: GameOverState(GameDataRef data) : _data(data){
    
}
void GameOverState::Init(){
    _data -> assets.LoadTexture("Game Over Background" , GAME_OVER_BG_FILEPATH);
    _background.setTexture(_data->assets.GetTexture("Game Over Background"));
    
}

void GameOverState::HandleInput(){
    sf::Event event;
    while(_data -> window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
        _data->window.close();
        }
    }
}
void GameOverState::Update(float dt){
    if(_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_SHOW_TIME){
        _data->machine.addState(StateRef(new MainMenuState(_data)), false);
    }
}
void GameOverState::Draw(float dt){
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
} 


void GameOverState::Pause(){

}
void GameOverState::Resume(){

}
