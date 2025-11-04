#include"../../include/game/Bird.h"
#include "../../include/DEFINITIONS.h"

Bird::Bird(GameDataRef data):_data(data){
    _animationIterator = 0;
    _animationFrames.push_back(_data->assets.GetTexture("Bird 1"));
    _animationFrames.push_back(_data->assets.GetTexture("Bird 2"));
    _animationFrames.push_back(_data->assets.GetTexture("Bird 3"));
    _animationFrames.push_back(_data->assets.GetTexture("Bird 4"));
    _birdSprite.setTexture(_animationFrames[_animationIterator]);
    sf::Vector2u WindowSize = _data->window.getSize();
    sf::FloatRect BirdBounds = _birdSprite.getGlobalBounds();
    _birdSprite.setPosition(WindowSize.x / 4 - BirdBounds.width / 2 , WindowSize.y / 2 - BirdBounds.height / 2);
    _birdState = BIRD_STATE_STILL;
}
Bird::~Bird(){

}
void Bird::Draw(){
    _data->window.draw(_birdSprite);
}
void Bird::Animate(float dt){
    const int N = _animationFrames.size();
    if(_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()){
        _animationIterator = (_animationIterator < N -  1) ? _animationIterator + 1 : 0;
        _birdSprite.setTexture(_animationFrames[_animationIterator]);
        _clock.restart();
    }
}
void Bird::Update(float dt){
    if(_birdState == BIRD_STATE_FALLING){
        _birdSprite.move(0 , GRAVITY * dt);
    }
    else if (_birdState = BIRD_STATE_FLYING){
        _birdSprite.move(0 , -FLYING_SPEED * dt);
    }

    if(_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION){
        _movementClock.restart();
        _birdState = BIRD_STATE_FALLING;
    }
 
}

void Bird::Tap(){
    _movementClock.restart();

    _birdState = BIRD_STATE_FLYING;

}
const sf::Sprite& Bird::GetSprite() const {
    return _birdSprite;
}