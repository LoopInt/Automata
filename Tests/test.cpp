#include "pch.h"

#include"Machine.h"
#include<string>

/*
Deux moyen de modeliser une machine :
	- implémentation simple avec un tableau 2D des états et transitions
		- Besoin de nommer les transitions
		-
*/

TEST(MachineTests, single_state_machine)
{
	Machine machine;
	State* state_a = machine.addState("A");
	machine.setInitialState(state_a);
	EXPECT_EQ(state_a, machine.currentState());
}

TEST(StateTests, transition_between_two_states)
{
	State state_a("A");
	State state_b("B");

	state_a.addTransition(0, &state_b);
	
	EXPECT_EQ(state_a.trigger(0), &state_b);
}

TEST(MachineTests, transition_between_two_states)
{
	Machine machine;
	State* state_a = machine.addState("A");
	State* state_b = machine.addState("B");

	machine.setInitialState(state_a);

	state_a->addTransition(0, state_b);
	state_b->addTransition(0, state_a);

	EXPECT_EQ(state_a, machine.currentState());
	machine.trigger(0);
	EXPECT_EQ(state_b, machine.currentState());
	machine.trigger(0);
	EXPECT_EQ(state_a, machine.currentState());
}

/*TEST(Machine, single_state_machine)
{
	Machine machine;
	State* state_a = machine.addState("A");
	State* state_b = machine.addState("B");
	machine.setInitialState(state_a);
	EXPECT_EQ(state_a, machine.currentState());
}*/