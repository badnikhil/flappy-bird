#include"../../include/game/Land.h"
#include"../../include/DEFINITIONS.h"
Land::Land(GameDataRef data) : _data(data){
    sf::Sprite sprite (_data->assets.GetTexture("Land"));
    sf::Sprite sprite2 (_data->assets.GetTexture("Land"));
    sprite.setPosition(0 , this->_data->window.getSize().y - sprite.getLocalBounds().height);
    sprite2.setPosition(sprite.getLocalBounds().width ,this->_data->window.getSize().y - sprite.getLocalBounds().height );
    _landSprites.push_back(sprite);
    _landSprites.push_back(sprite2);
}

void Land::MoveLand(float dt){
    for(int i = 0 ; i < _landSprites.size();i++){
        float movement = PIPE_MOVEMENT_SPEED * dt;
        _landSprites[i].move(-movement , 0);
        if(_landSprites[i].getPosition().x < 0 - _landSprites[i].getLocalBounds().width){
            _landSprites[i].setPosition(_data->window.getSize().x , _landSprites[i].getPosition().y);
        }
    }

}
void Land::DrawLand(){
    for(int i = 0 ; i < _landSprites.size();i++){
        _data->window.draw(_landSprites[i]);
    }
}
const std::vector<sf::Sprite>& Land::GetSprites()const{
    return _landSprites;
}