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

//CONSTRUCTOR
Network::Network(int i, int j)
:nb_exitatory(i), nb_inhibitory(j),CE_(i/10), CI_(j/10)
{
	//create the network of neurons
	create();
	
	//set connections between neurons
	setConnectivity();
}


void Network:: addNeuron()
{
	//add pointers of neurons
	network_.push_back(new Neuron());
}

void Network::create()
{
	//create nb_exitatory exitatory neurons
	for (int i(0); i<( nb_exitatory ); ++i)
	{
		addNeuron();
		network_[i]->setEx(true);
	
	}
	//create nb_inhibitory inhibitory neurons
	for (int i(nb_exitatory); i<(nb_inhibitory + nb_exitatory); ++i)
	{
		addNeuron();
		network_[i]->setEx(false);
	}
}

//GETTERS
double Network::getGlobalTime()
{
	return global_time_;
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
	
	//return an int between O and nb_exitatory-1
	uniform_int_distribution<> dis(0,nb_exitatory-1);
	
	//return an int between nb_exitatory and nb_exitatory+nb_inhibitory
	uniform_int_distribution<> d(nb_exitatory,nb_inhibitory+nb_exitatory-1); 
	
	
	for (size_t i=0; i<network_.size(); ++i)
	{
		for (int j = 0; j < CE_; j++)
		{
			//each neuron recieve CE_ connections with exitatory neurons
			network_[dis(gen)]->connect(i); 
		}
		for (int j = 0; j < CI_ ; j++)
		{	
			//each neuron recieve CI_ connections with inhibitory neurons
			network_[d(gen)]->connect(i);
		}	
	}
	
}

void Network::simulation(double tstart, double tstop, 
						 double I, int g, int poisson) 
{
	global_time_ = tstart;
	
	//open a file
	ofstream myfile;
	myfile.open("spikes.gdf");
	
	random_device rd;
	mt19937 gen(rd());
	
	//return an int following the poisson law
	poisson_distribution<int> pois(poisson);
		
	while((global_time_*0.1) < tstop) 
	{		
		for (size_t i = 0; i < network_.size(); i++)
		{
			//update each neuron
			//and if the neuron spikes :
			if (network_[i]->update(I,pois(gen)))
			{
				int delay (network_[i]->getDelay());
				int time (network_[i]->getInternalTime());
			
				//verify the stream with the file spikes.gdf
				assert(!myfile.fail());
			
				myfile<<global_time_*0.1<<"\t";
				myfile<< (i +1) <<endl;
			
			
			//for each neuron connected to the one that spiked
			//update its buffer 
			//according to the J of the neurons that spiked
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



//DESTRUCTOR
Network::~Network()
{
	for (size_t i = 0; i < network_.size(); i++)
	{
		//delete every pointers
		network_[i]=nullptr;
		delete network_[i];
	}
	
}
