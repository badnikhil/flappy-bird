#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "../state/State.h"
#include <SFML/Graphics.hpp>
#include "../game/Game.h"


class GameOverState : public State{
    public:
        GameOverState(GameDataRef data , int score);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Pause() override;
        void Resume() override;
        void Draw(float dt) override;
    private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _gameOverTitle;
    sf::Sprite _gameOverContainer;
    sf::Sprite _playButton;
    sf::Sprite _medal;
    sf::Text _scoreText;
    sf::Text _bestScoreText;
    int _score;
    int _bestScore = 0;
};

#endif