#include "../../include/DEFINITIONS.h"
#include "../../include/screens/GameState.h"

GameState:: GameState(GameDataRef data) : _data(data){
    
}
void GameState::Init(){
    _data->assets.LoadTexture("Game Background",GAME_BG_FILEPATH);
    _data->assets.LoadTexture("Pipe Up",PIPE_UP_FILEPATH);
    _data->assets.LoadTexture("Pipe Down",PIPE_DOWN_FILEPATH);
    _data->assets.LoadTexture("Land",LAND_FILE_PATH);
    _data->assets.LoadTexture("Bird 1",BIRD_FRAME_1_FILE_PATH);
    _data->assets.LoadTexture("Bird 2",BIRD_FRAME_2_FILE_PATH);
    _data->assets.LoadTexture("Bird 3",BIRD_FRAME_3_FILE_PATH);
    _data->assets.LoadTexture("Bird 4",BIRD_FRAME_4_FILE_PATH);
   
    pipe = new Pipe(_data);
    land = new Land(_data);
    bird = new Bird(_data);


    _background.setTexture(_data->assets.GetTexture("Game Background"));
    _gameState = GameStates::eReady;

    
}
void GameState::HandleInput(){
    sf::Event event;
    while(_data -> window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
        _data->window.close();
        }
        if(_data->input.IsSpriteClicked(_background , sf::Mouse::Left ,_data->window)){
            if(_gameState != GameStates::eGameOver) {
                bird->Tap();
                _gameState = GameStates::ePlaying;
            }
            
        }

    }
}
void GameState::Update(float dt){
    if(_gameState != GameStates::eGameOver){
        bird->Animate(dt);
        land->MoveLand(dt);
    }
    if(_gameState == GameStates::ePlaying){
        pipe->MovePipes(dt);
        bird->Update(dt);

        if(_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY){
            pipe->RandomisePipeOffset();

            pipe->SpawnTopPipe();
            pipe->SpawnBottomPipe();
            // pipe->SpawnInvisiblePipe();

            this->_clock.restart();
        }
        
    }
    

}
void GameState::Draw(float dt){
    _data->window.clear();
    _data->window.draw(_background);
    pipe->DrawPipes();
    land->DrawLand();
    bird->Draw();
    _data->window.display();
}


void GameState::Pause(){

}
void GameState::Resume(){

}
