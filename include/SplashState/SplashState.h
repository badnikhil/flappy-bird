#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include "../state/State.h"
#include "../game/Game.h"

class SplashState : public State{
    public:
        SplashState(GameDataRef data);
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
};



#endif