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

#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron_2.hpp"




using namespace std;

class Neuron; //pre-declaration

class Network 
{
	private:
//vont disparaitre

vector <Neuron*> network_;
double global_time_;
int nb_exitatory;
int nb_inhibitory;
int CE_;
int CI_;

	public:
Network(int i, int j);

//GETTERS
double getGlobalTime();
int getNetworkSize();
vector<Neuron*> getNetwork();
int compteur(int i);

void simulation (double tstart, double tstop, double I, int g, int poisson);	

void addNeuron();
void create();
void setConnectivity();

//void store();
	
~Network();
};

#endif
