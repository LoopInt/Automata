#pragma once

#include<string>
#include<map>
#include "DFA.h"

class DFABuilder
{
public:
	DFABuilder();
	DFA buildMachine();
	void reset();
	void addState(std::string stateName);
	void addSignal(char signal);
	void setInitialState(std::string state);
	void setFinalStates(std::vector<std::string> state);
	void setTransition(std::string initialState, char signal, std::string finalState);
private:
	DFA* _machine;
	std::vector<std::string> _states;
	std::vector<char> _signals;
	std::vector<std::map<char, int>*> _transitions;
	int _id_initial_state;
	std::vector<int> _finalStates;

	int getStateId(std::string name);
};
