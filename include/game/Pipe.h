#ifndef PIPE_H
#define PIPE_H
#include "Game.h"


class Pipe{
    public:
    Pipe(GameDataRef data);
    
    void SpawnBottomPipe();
    void SpawnTopPipe();
    void SpawnScoringLines();
    void MovePipes(float dt);
    void DrawPipes();
    void RandomisePipeOffset();
    const std::vector<sf::Sprite> &GetSprites()const;
    std::vector<sf::RectangleShape> &GetScoringLines();


    private:
    GameDataRef _data;
    std::vector<sf::Sprite> pipeSprites;
    std::vector<sf::RectangleShape> scoringLines;
    int _landHeight;
    int _pipeSpawnYOffset;


};


#endif 