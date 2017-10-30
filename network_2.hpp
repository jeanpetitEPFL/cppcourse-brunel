#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron_2.hpp"




using namespace std;

class Neuron; //pre-declaration

class Network 
{
	private:
//vont disparaitre

double global_time_;
int nb_exitatory= 10000;
int nb_inhibitory=2500;
int CE_=1000;
int CI_=250;

vector <Neuron*> network_;
vector <vector <int> > c_table_;


	public:
Network(int i, int j);

//GETTERS
double getGlobalTime();
int compteur(int i);

void simulation (double tstart, double tstop, double I);	

void addNeuron();
void set_connectivity();

	
~Network();
};

#endif
