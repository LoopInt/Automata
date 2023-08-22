#include "Machine.h"
#include<memory>

State* Machine::addState(const std::string& name)
{
	State *new_state = new State(name);
	_states.push_back(new_state);
	return new_state;
}

void Machine::setInitialState(State* initial_state)
{
	_currentState = initial_state;
}

State* Machine::currentState()
{
	return _currentState;
}

void Machine::trigger(char transition)
{
	State* new_currentState = _currentState->trigger(transition);
	if (new_currentState != nullptr)
	{
		_currentState = new_currentState;
	}
}
