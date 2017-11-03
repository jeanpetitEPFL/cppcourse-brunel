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
int compteur(int i);

void simulation (double tstart, double tstop, double I);	

void addNeuron();
void create();
void setConnectivity();

//void store();
	
~Network();
};

#endif
