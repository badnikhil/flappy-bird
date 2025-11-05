#include "../../include/game/Pipe.h"
#include "../../include/DEFINITIONS.h"

Pipe::Pipe(GameDataRef data): _data(data){
    _landHeight = _data->assets.GetTexture("Land").getSize().y;
    _pipeSpawnYOffset = 0;
}

void Pipe::DrawPipes(){
    const int N = pipeSprites.size();
    for(unsigned short int i = 0 ; i < N ; i++){
        this ->_data->window.draw(pipeSprites[i]);
    
    }
}
void Pipe::SpawnBottomPipe(){
    sf::Sprite pipe(_data->assets.GetTexture("Pipe Up"));
    pipe.setPosition(_data->window.getSize().x , _data->window.getSize().y - pipe.getLocalBounds().height - _pipeSpawnYOffset);
    pipeSprites.push_back(pipe);
}
void Pipe::SpawnTopPipe(){
    sf::Sprite pipe(_data->assets.GetTexture("Pipe Down"));
    pipe.setPosition(_data ->window.getSize().x , - _pipeSpawnYOffset);
    pipeSprites.push_back(pipe);
}
void Pipe::SpawnScoringLines(){
    sf::RectangleShape line({1,(float)_data->window.getSize().y});
    line.setPosition(_data ->window.getSize().x + _data->assets.GetTexture("Pipe Up").getSize().x ,0);
    scoringLines.push_back(line);
}
void Pipe::MovePipes(float dt){
    for(int i = 0 ; i < pipeSprites.size() ; i++){
        float movement = PIPE_MOVEMENT_SPEED * dt;
        if(pipeSprites[i].getPosition().x < 0 - pipeSprites[i].getGlobalBounds().width){
            pipeSprites.erase(pipeSprites.begin() + i);
        }
        else {
        pipeSprites.at(i).move(-movement, 0);
        }
        
	}
    for(int i = 0 ; i < scoringLines.size() ; i++){
        float movement = PIPE_MOVEMENT_SPEED * dt;
        if(scoringLines[i].getPosition().x < 0 - scoringLines[i].getGlobalBounds().width){
            scoringLines.erase(scoringLines.begin() + i);
        }
        else {
        scoringLines.at(i).move(-movement , 0);
        }
        
	} 
}
void Pipe::RandomisePipeOffset(){
    _pipeSpawnYOffset = rand() % (_landHeight + 1);
}
const std::vector<sf::Sprite>& Pipe::GetSprites() const {
    return pipeSprites;
}
 std::vector<sf::RectangleShape>& Pipe::GetScoringLines()  {
    return scoringLines;
}