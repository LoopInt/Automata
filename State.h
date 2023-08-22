#pragma once

#include<string>
#include<map>

class State
{
public:
	State(const std::string& name);
	const std::string name();
	State* trigger(char transition);
	void addTransition(char transition, State* new_state);
private:
	std::string _name;
	std::map<char, State*> transition_table;
};

