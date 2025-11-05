#include "../../include/screens/GameOverState.h"
#include "../../include/DEFINITIONS.h"
#include "../../include/screens/GameState.h"
#include "../../include/screens/MainMenuState.h"

#include<fstream>
#include <iostream>
GameOverState:: GameOverState(GameDataRef data , int score) : _data(data) , _score(score){
    
}
void GameOverState::Init(){
    std::ifstream readFile;
    readFile.open("data/HighScore.txt");
    if(readFile.is_open()){
        while(!readFile.eof()){
            readFile >> _bestScore;
            std::cout<<_bestScore<<std::endl;

        }
    }
    
    std::ofstream writeFile;
    writeFile.open("data/HighScore.txt");
    if(writeFile.is_open()){
        if(_score > _bestScore){
            _bestScore = _score;
        }
        writeFile << _bestScore;
    }
    _data -> assets.LoadTexture("Game Over Background" , GAME_OVER_BG_FILEPATH);
    _data -> assets.LoadTexture("Game Over Title",GAME_OVER_TITLE_FILEPATH);
    _data -> assets.LoadTexture("Game Over Container",GAME_OVER_BODY_FILEPATH);
    _data -> assets.LoadTexture("Bronze",BRONZE_MEDAL_FILEPATH);
    _data -> assets.LoadTexture("Silver",SILVER_MEDAL_FILEPATH);
    _data -> assets.LoadTexture("Gold",GOLD_MEDAL_FILEPATH);
    _data -> assets.LoadTexture("Platinum" , PLATINUM_MEDAL_FILEPATH);
    sf::Vector2u windowBounds = _data->window.getSize();
    _background.setTexture(_data->assets.GetTexture("Game Over Background"));
    _gameOverTitle.setTexture(_data->assets.GetTexture("Game Over Title"));
    _gameOverContainer.setTexture(_data ->assets.GetTexture("Game Over Container"));
    _playButton.setTexture(_data ->assets.GetTexture("Play Button"));

    _gameOverContainer.setPosition(windowBounds.x / 2 - _gameOverContainer.getGlobalBounds().width / 2 , windowBounds.y / 2 - _gameOverContainer.getGlobalBounds().height / 2);
    _gameOverTitle.setPosition(windowBounds.x / 2 - _gameOverTitle.getGlobalBounds().width / 2 , _gameOverContainer.getPosition().y - _gameOverTitle.getGlobalBounds().height * 1.2);
    _playButton.setPosition(windowBounds.x / 2 - _playButton.getGlobalBounds().width / 2 ,_gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + _playButton.getGlobalBounds().height * 0.2);
    
    _scoreText.setFont(_data->assets.GetFont("Flappy Font"));
    _scoreText.setString(std::to_string(_score));
    _scoreText.setCharacterSize(56);
    _scoreText.setFillColor(sf::Color::White);
    _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
    _scoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15));
    _bestScoreText.setFont(this->_data->assets.GetFont("Flappy Font"));
    _bestScoreText.setString(std::to_string(_bestScore));
    _bestScoreText.setCharacterSize(56);
    _bestScoreText.setFillColor(sf::Color::White);
    _bestScoreText.setOrigin(sf::Vector2f(_bestScoreText.getGlobalBounds().width / 2, _bestScoreText.getGlobalBounds().height / 2));
    _bestScoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78));

    if(_score > PLATINUM_MEDAL_SCORE)_medal.setTexture(_data -> assets.GetTexture("Platinum"));
    else if(_score > GOLD_MEDAL_SCORE)_medal.setTexture(_data -> assets.GetTexture("Gold"));
    else if(_score > SILVER_MEDAL_SCORE)_medal.setTexture(_data -> assets.GetTexture("Silver"));
    else if(_score > BRONZE_MEDAL_SCORE)_medal.setTexture(_data -> assets.GetTexture("Bronze"));
    
    _medal.setPosition(175 , 465);
}

void GameOverState::HandleInput(){
    sf::Event event;
    while(_data -> window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
        _data->window.close();
        }
        if(_data->input.IsSpriteClicked(_playButton , sf::Mouse::Left , _data->window)){
            _data->machine.addState(StateRef(new GameState(_data)) , true);
        }
    }
}
void GameOverState::Update(float dt){
   
}
void GameOverState::Draw(float dt){
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_playButton);
    _data->window.draw(_gameOverTitle);
    _data->window.draw(_gameOverContainer);
    _data->window.draw(_bestScoreText);
    _data->window.draw(_scoreText);
    _data -> window.draw(_medal);
    _data->window.display();
} 


void GameOverState::Pause(){

}
void GameOverState::Resume(){

}
