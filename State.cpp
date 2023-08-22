#include "State.h"

State::State(const std::string& name)
{
    _name = name;
}

const std::string State::name()
{
    return std::string();
}

State* State::trigger(char transition)
{
    std::map<char, State*>::iterator new_state = transition_table.find(transition);
    if (new_state == transition_table.end())
    {
        return nullptr;
    }

    return new_state->second;
}

void State::addTransition(char transition, State* new_state)
{
    transition_table[transition] = new_state;
}
