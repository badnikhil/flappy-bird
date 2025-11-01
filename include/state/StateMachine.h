#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "State.h"
#include <memory>
#include <stack>
typedef std::unique_ptr<State> StateRef;
class StateMachine{
    private:
        std::stack<StateRef> _States;
        StateRef _newState;
        bool _isAdding;
        bool _isReplacing;
        bool _isRemoving;
    public:
        StateMachine( ){ }
        ~StateMachine( ){ }

        void addState(StateRef newState , bool isReplacing); 
        void removeState();
        void processStateChanges();
        StateRef &getActiveState();
         
};

#endif