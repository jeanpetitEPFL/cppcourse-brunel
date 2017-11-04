/**	
	@class Network
	@author Jeanpetit FLorent
	@date 10/2017
    @brief network
 
	
	@details 
	purpose of the network class
	- create a network of neurons
	- set connnections between neurons in the same network
	- create a simulation loop which represent the running of a "brain"
*/

#include "network_2.hpp"

using namespace std;

Network::Network(int i, int j)
:nb_exitatory(i), nb_inhibitory(j),CE_(i/10), CI_(j/10)
{
	
	create();
	setConnectivity();
}


void Network:: addNeuron()
{
	network_.push_back(new Neuron());
}

void Network::create()
{
	for (int i(0); i<( nb_exitatory ); ++i)
	{
		addNeuron();
		network_[i]->setEx(true);
	
	}
	for (int i(nb_exitatory); i<(nb_inhibitory + nb_exitatory); ++i)
	{
		addNeuron();
		network_[i]->setEx(false);
	}
	
}
int Network::getNetworkSize()
{
	return network_.size();
}
vector<Neuron*> Network::getNetwork()
{
	
	return network_;
}
void Network:: setConnectivity()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0,nb_exitatory-1);
	uniform_int_distribution<> d(nb_exitatory,nb_inhibitory+nb_exitatory-1); 
	
	for (size_t i=0; i<network_.size(); ++i)
	{
		for (int j = 0; j < CE_; j++)
		{
			network_[dis(gen)]->connect(i); 
		}
		for (int j = 0; j < CI_ ; j++)
		{	
			network_[d(gen)]->connect(i);
		}	
	}
	
}

double Network::getGlobalTime()
{
	return global_time_;
}


void Network::simulation(double tstart, double tstop, 
				double I, int g, int poisson) 
{
	global_time_ = tstart;

	ofstream myfile;
	myfile.open("spikes.gdf");
	
	random_device rd;
	mt19937 gen(rd());
	poisson_distribution<int> pois(poisson);
		
	while((global_time_*0.1) < tstop) 
	{		
		for (size_t i = 0; i < network_.size(); i++)
		{
			if (network_[i]->update(I,pois(gen)))
			{
			int delay (network_[i]->getDelay());
			int time (network_[i]->getInternalTime());
			
			myfile<<global_time_*0.1<<"\t";
			myfile<< (i +1) <<endl;
			
			for (auto& element:network_[i]->getConnections())
			{	
				if (network_[i]->getEx()==true)
				{		
					double J(network_[i]->getJ());
					network_[element]->
					updatebuffer((time + delay)%(delay+1),J);
				}
				if(network_[i]->getEx()==false)
				{
					double J(network_[i]->getJ()*g);
					network_[element]->
					updatebuffer((time + delay)%(delay+1),J);
				}
			}		
			}
		}		
		global_time_ += 1 ;
	}
	myfile.close();
}	




Network::~Network()
{
	for (size_t i = 0; i < network_.size(); i++)
	{
		network_[i]=nullptr;
		delete network_[i];
	}
	
}
