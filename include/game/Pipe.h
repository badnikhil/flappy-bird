#ifndef PIPE_H
#define PIPE_H
#include "Game.h"


class Pipe{
    public:
    Pipe(GameDataRef data);
    
    void SpawnBottomPipe();
    void SpawnTopPipe();
    void SpawnInvisiblePipe();
    void MovePipes(float dt);
    void DrawPipes();
    void RandomisePipeOffset();


    private:
    GameDataRef _data;
    std::vector<sf::Sprite> pipeSprites;
    int _landHeight;
    int _pipeSpawnYOffset;


};


#endif 