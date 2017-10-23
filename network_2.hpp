#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron_2.hpp"




using namespace std;

class Neuron; //pre-declaration

class Network 
{
	private:
//vont disparaitre
Neuron alpha_;
Neuron beta_;

double global_time_;
int nb_exitatory= 10000;
int nb_inhibitory=2500;
int CE_=1000;
int CI_=250;

vector <Neuron*> network_;
vector <vector <int>> c_table_;


	public:
Network(Neuron a, Neuron b);

//GETTERS
double getGlobalTime();
int compteur(int i);

int simulation (double tstart, double tstop, double I);	

void addNeuron();
void set_connectivity();

	
//~Network();
};

#endif
