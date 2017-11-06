#include <iostream>
#include "neuron.hpp"
#include "network.hpp"
//#include "/usr/include/gtest.h"
#include <gtest/gtest.h>
//#include "googletest-master/googletest/include/gtest/gtest.h"

/**
 *	test one neuron
 *	the potential after one update
 */ 
TEST (SingleNeuronTest, Neuron_Potential) 
{
	Neuron neuronA;
	
	neuronA.update(1,0);
	EXPECT_EQ(20*(1.0-exp(-0.1/20)), neuronA.getMembpot());
}

/**
 *	test one neuron
 *	time of the first spike
 */ 
TEST (SingleNeuronTest, Neuron_SpikeTime01)
{
	Neuron neuronA;
	
	for (int i = 0; i < 1000; i++)
	{
		neuronA.update(1.01,0);
	}
	EXPECT_EQ(92.4, neuronA.getSpikesTime()[0]);
	EXPECT_EQ(1, neuronA.getNbSpikes());
}

/**
 *	test one neuron
 *	time of the second spike
 */ 
TEST (SingleNeuronTest, Neuron_SpikeTime02)
{
	Neuron neuronA;
	
	for (int i = 0; i < 2000; i++)
	{
		neuronA.update(1.01,0);
	}

	EXPECT_EQ(186.8, neuronA.getSpikesTime()[1]);
	EXPECT_EQ(2, neuronA.getNbSpikes());
}

/**
 *	test one neuron
 *	time of the third spike
 */ 
TEST (SingleNeuronTest, Neuron_SpikeTime03)
{
	Neuron neuronA;
	
	for (int i = 0; i < 3000; i++)
	{
		neuronA.update(1.01,0);
	}
	
	EXPECT_EQ(281.2, neuronA.getSpikesTime()[2]);
	EXPECT_EQ(3, neuronA.getNbSpikes());
}

/**
 *	test one neuron
 *	number of spike with an external current I=1.00
 */ 
TEST (SingleNeuronTest, Neuron_SpikeTime04)
{
	Neuron neuronA;
	
	for (int i = 0; i < 5000; i++)
	{
		neuronA.update(1.0,0);
	}
	
	EXPECT_EQ(0, neuronA.getNbSpikes());
}

/**
 *	test two neurons interaction
 *	buffer of neuronB if A and B connected
 */ 
TEST(TwoNeuronTest, Buffer) 
{

	Neuron neuronA;
	Neuron neuronB;

	int time (neuronA.getInternalTime());
	int delay(neuronA.getDelay());
	double J(neuronA.getJ());
	
	for(int i(0); i < (938); ++i) 
	{	
		if(neuronA.update(1.01, 0))
		{
			neuronB.updatebuffer((time+delay)%(delay+1),J);
		}
		neuronB.update(0,0);
	}
	EXPECT_NEAR(0.1, neuronB.getMembpot(), 10e-3); 
}

/**
 *	test network
 *	test size of network
 */ 
TEST(NetworkTest, Network_Size )
{
	Network net(10000,2500);
	EXPECT_EQ(12500, net.getNetworkSize());
}

/**
 *	test network
 *	test nature of neuron inside network
 */ 
TEST(NetworkTest, Nature_Of_Neurons)
{
	Network net(10000,2500);
	int True(0);
	int False(0);
	for (auto& element : net.getNetwork())
	{
		if(element->getEx())
		{  ++ True; }
		if(!element->getEx())
		{  ++False; }
	}
	EXPECT_EQ(10000, True);
	EXPECT_EQ(2500, False);
}

/**
 *	test network
 *	test global time of network
 */ 
TEST(NetworkTest, Network_Time)
{
	Network net(10000,2500);
	net.simulation(0,100,0,5,2);
	EXPECT_EQ(1000, net.getGlobalTime());

}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}
