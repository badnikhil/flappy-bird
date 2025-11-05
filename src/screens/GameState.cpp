#include "../../include/DEFINITIONS.h"
#include "../../include/screens/GameState.h"
#include "../../include/screens/GameOverState.h"
#include <iostream>

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
    _data->assets.LoadFont("Flappy Font",FLAPPY_FONT_FILE_PATH);
   
    pipe = new Pipe(_data);
    land = new Land(_data);
    bird = new Bird(_data);
    flash = new Flash(_data);
    hud = new HUD(_data);
   


    _background.setTexture(_data->assets.GetTexture("Game Background"));
    _gameState = GameStates::eReady;
    _score = 0;

    
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
            pipe->SpawnScoringLines();

            this->_clock.restart();
        }
        const std::vector<sf::Sprite> landSprites = land->GetSprites();
        const sf::Sprite birdSprite = bird->GetSprite();
        for(sf::Sprite sprite : landSprites){
            if(collision.CheckSpriteCollision(birdSprite , 1 , sprite , 1.0f)){
                _gameState = GameStates::eGameOver;
                _clock.restart();
            }
        }

        const std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();
        for(sf::Sprite sprite : pipeSprites){
            if(collision.CheckSpriteCollision(birdSprite , 0.9 , sprite , 1.0f)){
                _gameState = GameStates::eGameOver;
                _clock.restart();
            }
        }
         std::vector<sf::RectangleShape> &scoringLines = pipe->GetScoringLines();
        for(int i = 0 ; i < scoringLines.size() ; i++){
            float bird = birdSprite.getPosition().x;
            float lineX = scoringLines[i].getPosition().x;
            if (bird > lineX) {
                _score++;
                hud->UpdateScore(_score);
                std::cout<<_score<<std::endl;
                scoringLines.erase(scoringLines.begin() + i);
                break;
            }
        }
    }

    if(_gameState == GameStates::eGameOver){
        flash->Show(dt);
        if(_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS){
            _data->machine.addState(StateRef(new GameOverState(_data , _score)) , true);
        }
    }
    

}
void GameState::Draw(float dt){
    _data->window.clear();
    _data->window.draw(_background);
    pipe->DrawPipes();
    land->DrawLand();
    bird->Draw();
    flash->Draw();
    hud->Draw();
    _data->window.display();
}


void GameState::Pause(){

}
void GameState::Resume(){

}
