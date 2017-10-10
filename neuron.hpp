#ifndef NEURON_HPP	
#define NEURON_HPP
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>


using namespace std;

class Neuron
{
private :
	double membrane_pot_;
	int nb_spikes_;
	vector <double> spikes_time_;
	vector <double> time_buffer_;
	
// initial state of the values
// can be changed of place	
// INITIALIZED IN CONSTRUCTOR BY DEFAULT
// CAN BE CHANGED IN THE OTHER CONSTRUCTOR
	double C_; //conductance
	double tau_;
	double tau_ref_;
	double Vreset_;
	double Vthreshold_;
	double h_;
	double R_;
	
// internal time of ONE neuron
// can become a global time if needed	
	double internal_time_;


	
	
public :
	Neuron();
	Neuron (double c,double t,double tr,double v,double vt, double h,double r);
	
//methods used in update, to determine and set potential	
	void ifPotMaxReached();
	void SetPot(double I);
	void SetNewPot();
	
//update neuron's potential state
	void update (double I);
	
//SETTERS	
	void setMembPot(double m);
	void setNbSpikes (int nbs);

// GETTERS	
	double getH();
	double getMembpot();
	int getNbSpikes();
	double getInternalTime();
	
	vector<double> getSpikesTime();
	

	
	~Neuron();
};
#endif
