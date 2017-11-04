#include <iostream>
#include "neuron_2.hpp"
#include "network_2.hpp"
#include "googletest-master/googletest/include/gtest/gtest.h"

TEST (SingleNeuronTest, Neuron_Potential) 
{
	Neuron neuronA;
	
	neuronA.update(1,0);
	EXPECT_EQ(20*(1.0-exp(-0.1/20)), neuronA.getMembpot());
}

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

TEST (SingleNeuronTest, Neuron_SpikeTime04)
{
	Neuron neuronA;
	
	for (int i = 0; i < 5000; i++)
	{
		neuronA.update(1.00,0);
	}
	
	EXPECT_EQ(0, neuronA.getNbSpikes());
}

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


TEST(Networktest, Network_Time )
{

	Network net(10000,2500);
	
EXPECT_EQ(12500, net.getNetworkSize());
net.simulation(0,100,0,5,2);
EXPECT_EQ(1000, net.getGlobalTime());


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
