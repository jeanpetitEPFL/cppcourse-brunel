#include <iostream>
#include "neuron_2.hpp"
#include "network_2.hpp"
#include "googletest-master/googletest/include/gtest/gtest.h"

TEST (NeuronTest, SingleNeuron_Potential) 
{
	Neuron neuronA;
	
	//first update test
	neuronA.update(1,0);
	EXPECT_EQ(20*(1.0-exp(-0.1/20)), neuronA.getMembpot());
}

TEST (NeuronTest, NeuronSpikeTime)
{
	Neuron neuronA;
	
	for (int i = 0; i < 5000; i++)
	{
		neuronA.update(1.01,0);
	}
	EXPECT_EQ(92.4, neuronA.getSpikesTime()[0]);
	EXPECT_EQ(186.8, neuronA.getSpikesTime()[1]);
	EXPECT_EQ(281.2, neuronA.getSpikesTime()[2]);
	

}


TEST(Networktest, network )
{

	Network net(10000,2500);
	
//	EXPECT_EQ

		//net.simulation(0,200, 1.01);
	//second simulation test
	//EXPECT_EQ(2, net.compteur(net.simulation(0,200, 1.01)));
	//melzvhzeogh

}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}
