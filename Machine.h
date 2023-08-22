#pragma once

#include<string>
#include<vector>
#include"State.h"

class Machine
{
public:
	State* addState(const std::string &name);
	void setInitialState(State* initial_state);
	State* currentState();
	void trigger(char transition);
	//void addTransition(const std::string& name);
private:
	State* _currentState;
	std::vector<State*> _states;

};

