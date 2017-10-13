#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron_2.hpp"




using namespace std;

class Neuron; //pre-declaration

class Network 
{
	private:

Neuron alpha_;
Neuron beta_;
double global_time_;

	public:
Network(Neuron a, Neuron b);

//GETTERS
double getGlobalTime();

void simulation (double tstart, double tstop, double I);	
	
//~Network();
};

#endif
