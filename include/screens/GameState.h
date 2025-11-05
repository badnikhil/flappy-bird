#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "../state/State.h"
#include <SFML/Graphics.hpp>
#include "../game/Game.h"
#include "../game/Pipe.h"
#include "../game/Land.h"
#include "../game/Bird.h"
#include "../game/Collision.h"
#include "../game/Flash.h"
#include "../game/HUD.h"

class GameState : public State{
    public:
        GameState(GameDataRef data);
        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Pause() override;
        void Resume() override;
        void Draw(float dt) override;
    private:
    GameDataRef _data;
    sf::Sprite _background;
    Pipe *pipe;
    sf::Clock _clock;
    Land *land;
    Bird *bird;
    Flash *flash;
    Collision collision;
    HUD *hud;

    int _gameState;
    int _score;
};
#endif