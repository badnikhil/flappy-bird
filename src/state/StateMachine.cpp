#include "../../include/state/StateMachine.h"

void StateMachine::addState(StateRef newState, bool isReplacing){
    this -> _isAdding = true;
    this -> _isReplacing = isReplacing;
    this -> _newState = move(newState);
}
void StateMachine::removeState(){
    _isRemoving = true;
}
void StateMachine::processStateChanges(){
    if(_isRemoving && !this -> _States.empty()){
        this->_States.pop();
        if(!_States.empty()){
           this -> _States.top()->Resume();
        }
        this -> _isRemoving = false;
    }
    if(this -> _isAdding){
        if(!_States.empty()){
        if(this -> _isReplacing){
            _States.pop();
        }
        else _States.top()->Pause();
    
        }
        this -> _States.push(std::move(this -> _newState));
        _States.top() -> Init();
        _isAdding = false;
    }

}
StateRef& StateMachine::getActiveState(){
    return _States.top();
}