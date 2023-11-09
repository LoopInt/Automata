#include "DFA.h"

DFA::DFA()
{
}

std::string DFA::currentState()
{
	return _states[_currentState];
}

void DFA::trigger(char signal)
{
	_currentState = _transitions->get(_currentState, signal);
}

bool DFA::run(std::string inputs)
{
	bool result = false;
	for (auto c : inputs)
	{
		trigger(c);
	}

	for (auto finalState : _finalStates)
	{
		if (finalState == _currentState)
		{
			result = true;
			break;
		}
	}

	reset();
	return result;
}

void DFA::reset()
{
	_currentState = _initialState;
}
