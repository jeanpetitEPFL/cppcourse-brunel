#include <iostream>
#include "neuron_2.hpp"
#include "GTEST_DIR/googletest/include/gtest/gtest.h"

TEST (NeuronTest, MenbranePotential) 
{
	Neuron neuron(15, 0.4);
	
	//first update test
	neuron.update(1);
	EXPECT_EQ(20*(1.0-exp(-0.1/20)), neuron.getMembpot());
	
}
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}
