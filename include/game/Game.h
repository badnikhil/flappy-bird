#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <memory>
#include "../InputManager/InputManager.h"
#include "../asset/AssetManager.h"
#include "../state/StateMachine.h"


struct GameData{
    StateMachine machine;
    AssetManager assets;
    sf::RenderWindow window;
    InputManager input;
};
typedef std::shared_ptr<GameData> GameDataRef;

class Game{
    public:
        Game(int height , int width , std::string title);
    private:
        const float dt = 1.0f / 60.0f;
        GameDataRef _data = std::make_shared<GameData>();
        sf::Clock _clock;

        void run();

};

#endif 