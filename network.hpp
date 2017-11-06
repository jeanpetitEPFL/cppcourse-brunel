/**	
	@class Network
	@author Jeanpetit FLorent
	@date 05/11/2017
    @brief network
 
	
	@details 
	purpose of the network class
	- create a network of neurons
	- set connnections between neurons in the same network
	- create a simulation loop which represent the running of a "brain"
*/

#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.hpp"




using namespace std;

//pre-declaration
class Neuron; 

class Network 
{
	private:

vector <Neuron*> network_;
double global_time_;
int nb_exitatory;
int nb_inhibitory;
int CE_;
int CI_;

	public:
	
//CONSTRUCTOR
/**
 *	@a constructor of network :
 *	create the network of neurons and set the connections between them
 *	@param int : i, number of exitatory neurons
 *	@param int : j, number of inhibitory neurons
 */
Network(int i, int j);

//GETTERS
/**
 *	return time of the simulation
 *	@return double
 */
double getGlobalTime();

/**
 *	return size of the network = number of neurons
 *	@return int
 */
int getNetworkSize();

/**
 *	return the table of neurons present in the network
 *	@return vector<Neuron*>
 */
vector<Neuron*> getNetwork();

/**
 *	during the time (Tstop - Tstart)
 *	each neuron of the network is updated.
 *	 If a neuron spikes the time is stored in a file "spikes.gdf",
 *	and each neuron's buffer connected to this neuron is updated
 *	@return void
 *	@param double : time start of the simulation
 *	@param double : time end  of the simulation
 *	@param double : external current I
 *	@param int : g for Vext/Vthreshold
 *	@param int : poisson for background noise
 */
void simulation (double tstart, double tstop, double I, int g, int poisson);	

/**
 *	add a neuron in the vector network
 *	@return void
 */
void addNeuron();
/**
 *	create the network with number of neurons
 *	(exitatory and inhibitory) wished
 *	@return void  
 */
void create();

/**
 *	set connections between different neurons;
 *	CE_ connections with exitatory neurons,
 * 	CI_ connections with inhibitory neurons
 *	@return void
 * 
 */
void setConnectivity();

/**
 *	@a destructor
 *	delete every pointers present in the vector network
 */	
~Network();
};

#endif
