#include "../../include/screens/MainMenuState.h"
#include "../../include/DEFINITIONS.h"
#include "../../include/screens/GameState.h"


MainMenuState:: MainMenuState(GameDataRef data) : _data(data){

}
void MainMenuState::Init(){
    _data->assets.LoadTexture("Main Menu Background",MAIN_MENU_BG_FILEPATH);
    _data->assets.LoadTexture("Play Button" , PLAY_BUTTON_FILEPATH);
    _data->assets.LoadTexture("Game Title" , GAME_TITLE_FILEPATH);
    _background.setTexture(_data->assets.GetTexture("Main Menu Background"));
    _playButton.setTexture(_data->assets.GetTexture("Play Button"));
    _title.setTexture(_data->assets.GetTexture("Game Title"));
    sf::Vector2u WindowSize = _data->window.getSize();
    _title.setPosition( WindowSize.x/ 2 - _title.getGlobalBounds().width / 2 , _title.getGlobalBounds().height / 2 );
    _playButton.setPosition(WindowSize.x / 2 - _playButton.getGlobalBounds().width / 2 , WindowSize.y / 2 - _playButton.getGlobalBounds().height / 2);

    
}
void MainMenuState::HandleInput(){
    sf::Event event;
    while(_data -> window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
        _data->window.close();
        }
        if(_data->input.IsSpriteClicked(_playButton , sf::Mouse::Left , _data->window)){
            _data -> machine.addState(StateRef(new GameState(_data)),true);
        }
    }
}
void MainMenuState::Update(float dt){

}
void MainMenuState::Draw(float dt){
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_title);
    _data->window.draw(_playButton);
    _data->window.display();
}


void MainMenuState::Pause(){

}
void MainMenuState::Resume(){

}