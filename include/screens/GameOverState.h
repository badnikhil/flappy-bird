#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "../state/State.h"
#include <SFML/Graphics.hpp>
#include "../game/Game.h"


class GameOverState : public State{
    public:
        GameOverState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Pause() override;
        void Resume() override;
        void Draw(float dt) override;
    private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _background;
    sf::Sprite _title;
    sf::Sprite _playButton;
};

#endif