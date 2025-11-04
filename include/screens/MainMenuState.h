#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "../state/State.h"
#include <SFML/Graphics.hpp>
#include "../game/Game.h"


class MainMenuState : public State{
    public:
        MainMenuState(GameDataRef data);
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