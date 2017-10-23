#ifndef NEURON_HPP	
#define NEURON_HPP
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cassert>



using namespace std;

class Neuron
{
	private:

double membrane_pot_;
int nb_spikes_;
vector <double> spikes_time_;
vector <double> time_buffer_;
int delay_;	
int internal_time_;
//true if exitatory
//false if inhibitory
bool E_;
double J_ = 0.1;


	 double C_ =(40.0); 
	 double tau_ =(20.0);
	 double tau_ref_ =(2.0);
	 double Vreset_ =(0.0);
	 double Vthreshold_ =(20.0);
	 double h_ =(0.1);
	 double R_ =(20.0);
	
	public:
	
//CONSTRUCTORS	
Neuron(int Delay, double J);

// GETTERS	
double getH() const;
double getMembpot() const ;
	/**
	 * @return number of spikes occured 
	 */
int getNbSpikes() ;
int getInternalTime() const;
int getDelay() const;	

	
vector<double> getSpikesTime();


//SETTERS
void setMembPot(double m);
void setNbSpikes (int nbs);
void setEx(bool alpha);



//methods used in update, to determine and set potential	
bool ifPotMaxReached();
void PotMaxReached();
void SetPot(double I);
void SetNewPot();
bool Refractory();

//update neuron's potential state
bool update (double const& I);
	
//update buffer
void updatebuffer (int pos, Neuron n);

//DESTRUCTOR
//~Neuron();	
};


#endif
