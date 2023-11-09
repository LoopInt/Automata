#pragma once

#include<vector>
#include<string>
#include"Array2D.h"

class DFA
{
	friend class DFABuilder;
public:
	DFA();
	std::string currentState();
	void trigger(char signal);
	bool run(std::string inputs);
	void reset();
protected:
	Array2D<int> *_transitions;
	std::vector<std::string> _states;
	std::vector<int> _finalStates;
	int _initialState;
	int _currentState;
};

