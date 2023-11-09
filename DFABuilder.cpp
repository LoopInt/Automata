#include "DFABuilder.h"

DFABuilder::DFABuilder()
{
    _id_initial_state = -1;
    reset();
}

DFA DFABuilder::buildMachine()
{
    if (_machine == nullptr)
    {
        delete _machine;
    }
    _machine = new DFA;

    _machine->_states = _states;

    _machine->_initialState = _id_initial_state;

    for (auto stateId : _finalStates)
    {
        _machine->_finalStates.push_back(stateId);
    }
    
    unsigned int nb_columns = 255;

    _machine->_transitions = new Array2D<int>(_machine->_states.size(), nb_columns);

    // transition vers son état actuel par defaut
    for (int i = 0; i < _machine->_transitions->getNbLines(); i++)
    {
        for (int j = 0; j < _machine->_transitions->getNbColumns(); j++)
        {
            _machine->_transitions->set(i, j, i);
        }
    }

    //spécification des transisitons
    for (int i = 0 ; i<_transitions.size(); i++)
    {
        auto state_transition = _transitions[i];

        for (auto j = state_transition->begin(); j!= state_transition->end(); j++)
        {
            _machine->_transitions->set(i, j->first, j->second);
        }
    }

    return *_machine;
}

void DFABuilder::reset()
{
    _finalStates.clear();
    _id_initial_state = -1;
    if (_machine == nullptr)
    {
        delete _machine;
    }
    _machine = new DFA;
}

void DFABuilder::addState(std::string stateName)
{
    _states.push_back(stateName);
    _transitions.push_back(new std::map<char, int>);
}

void DFABuilder::addSignal(char signal)
{
    _signals.push_back(signal);
}

void DFABuilder::setInitialState(std::string state)
{
    for (int i = 0; i<_states.size(); i++)
    {
        if (_states[i] == state)
        {
            _id_initial_state = i;
            return;
        }
    }
}

void DFABuilder::setFinalStates(std::vector<std::string> states)
{
    for (auto state : states)
    {
        for (int i = 0; i < _states.size(); i++)
        {
            if (_states[i] == state)
            {
                _finalStates.push_back(i);
                break;
            }
        }
    }
}

void DFABuilder::setTransition(std::string initialState, char signal, std::string finalState)
{
    int state_id = getStateId(initialState);
    int final_state_id = getStateId(finalState);
    auto state_transition = _transitions[state_id];
    (*state_transition)[signal] = final_state_id;
}

int DFABuilder::getStateId(std::string name)
{
    int i = 0;

    for (auto it = _states.begin(); it != _states.end(); it++)
    {
        if (*it == name)
        {
            return i;
        }

        i++;
    }
    return -1;
}
