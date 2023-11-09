#include "pch.h"

#include"DFA.h"
#include"DFABuilder.h"
#include<string>
#include<vector>


TEST(MachineTests, single_state_machine)
{
	DFABuilder builder;
	builder.addState("A");
	builder.setInitialState("A");
	DFA machine = builder.buildMachine();
	EXPECT_EQ("A", machine.currentState());
}

TEST(StateTests, transition_between_two_states)
{
	DFABuilder builder;
	builder.addState("A");
	builder.addState("B");
	builder.addSignal(0);

	builder.setInitialState("A");
	builder.setTransition("A", 0, "B");

	DFA machine = builder.buildMachine();
	machine.trigger(0);
	
	EXPECT_EQ(machine.currentState(), "B");
}

TEST(StateTests, single_state_machine)
{
	DFABuilder builder;
	builder.addState("A");
	builder.setInitialState("A");

	DFA machine = builder.buildMachine();

	EXPECT_EQ(machine.currentState(), "A");
}

TEST(StateTests, scenario)
{
	DFABuilder builder;
	builder.addState("A");
	builder.addState("B");
	builder.addState("C");

	builder.setFinalStates({ "C" });

	builder.setInitialState("A");

	builder.addSignal(0);
	builder.addSignal(1);

	builder.setTransition("A", 1, "B");
	builder.setTransition("B", 0, "C");
	builder.setTransition("B", 1, "A");
	builder.setTransition("C", 0, "B");

	DFA machine = builder.buildMachine();

	EXPECT_TRUE(machine.run({ 1,0 }));
	EXPECT_FALSE(machine.run({ 1,1 }));
}
