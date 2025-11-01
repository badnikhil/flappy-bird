#ifndef STATE_H
#define STATE_H
class State{
     public:
        virtual void init() = 0;
        virtual void handleinput() = 0;
        virtual void update(float dt) = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void draw(float dt) = 0;
};
#endif
