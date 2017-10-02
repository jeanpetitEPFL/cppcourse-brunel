#ifndef NEURsON_HPP	
#define NEURON_HPP
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Neuron
{
private :
	double membrane_pot_;
	int nb_spikes_;
	vector <double> spikes_time_;
	double C_; //conductance
	double R_;
	double tau_;
	double tau_ref_;
	double Vreset_;
	double h_;
	double internal_time_;


	
	
public :
	Neuron();
	void update (double& h, double& I);
	void setMembPot(double m);
	void setNbSpikes (int nbs);
	/*void setTime (vector <double> t);*/
	
	double getMembpot();
	int getNbSpikes();
	vector<double> getSpikesTime();
	
	~Neuron();
};
#endif
