/**	
	@class Neuron
	@author Jeanpetit FLorent
	@date 10/2017
    @brief neuron
 
	
	@details 
	purpose of the class neuron :
	- create a neuron
	- update the neuron's potential in function of internal time
	- store connections between neurons
*/

#ifndef NEURON_HPP	
#define NEURON_HPP
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cassert>
#include <random>


using namespace std;

class Neuron
{
	private:

double membrane_pot_;
int nb_spikes_;
vector <double> spikes_time_;
vector <double> time_buffer_;
int delay_= 15;	
int internal_time_;
bool E_;
double J_ = (0.1);
vector <int> connections_;
double C_ =(40.0); 
double tau_ =(20.0);
double tau_ref_ =(2.0);
double Vreset_ =(0.0);
double Vthreshold_ =(20.0);
double h_ =(0.1);
double R_ =(20.0);

	
	public:
	
//CONSTRUCTORS	
/**
 *	@a constructor of neuron
 */
Neuron ();

// GETTERS	

/**
 *	return step time = 0.1 ms  
 *	@return double
 */
double getH() const;

/**
 *	return membrane potential of the neuron
 *	@return double
 */
double getMembpot() const ;

/**
 *	return number of spikes occured 
 *	@return int
 */
int getNbSpikes() const;

/**
 *	return the intetnal time of the neuron
 *	@return int 
 */
int getInternalTime() const;

/**
 *	return the delay
 *	@return int 
 */
int getDelay() const;	

/**
 *	return true if the neuron is an exitatory neuron,
 *	false if not
 *	@return bool  
 */
bool getEx();

/**
 *	return J
 *	@return double
 */
double getJ();

/**
 *	return a table of time
 *	when spikes occured for this neuron
 *	@return vector<double> 
 */
vector<double> getSpikesTime();

/**
 *	return the time of the last spikes that occured
 *	@return double
 */
double getLastTimeSpike();

/**
 *	return the vector of connections of this neuron
 *	@return vector<int> 
 */
vector<int> getConnections();


//SETTERS
/**
 *	set membrane potential
 *	@return void 
 *	@param double
 */
void setMembPot(double m);

/**
 *	set the number of spikes 
 *	@return void
 *	@param int
 */
void setNbSpikes (int nbs);

/**
 *	set the boolean E:
 * 	true for exitatory neuron and false for inhibitory neuron
 *	@return double 
 *	@param boolean
 */
void setEx(bool alpha);


/**
 *	return yes if Vthreshold is reached
 *	@return bool
 */	
bool ifPotMaxReached();
/**
 *	if Vthreshold is reached :
 * 	increase the numbde of spike and set the potential to Vreset=0
 *	@return void 
 */
void PotMaxReached();

/**
 *	set the new potential with the buffer, the background noise,
 *	the external current
 *	@return void
 *	@param int : external current I
 * 	@param int : poisson distribution
 */
void SetPot(double I, int pois);

/**
 *	if Vthreshold is reached,
 * 	set the membrane potential to 0=Vreset
 *	@return void
 *	@param double :external current I
 *	@param int : poisson
 */
void SetNewPot();

/**
 *	return true if the neuron is not in refractory time,
 *	false if not
 *	@return bool 
 */
bool Refractory();

/**
 *	method used in class Network,
 *	will add a connection between 2 neurons
 *	@return void
 *	@param int : position
 */
void connect(int i);


/**
 *	update potential each step time,
 *	in function of the refractory time, 
 *	return true if the neuron spikes
 *	@return bool
 *	@param double : external current I
 *	@param int : poisson
 */
bool update (double const& I, int pois);
	

/**
 *	insert a new value in the buffer 
 *	@return void 
 *	@param int buffer's position
 *	@param double value
 */
void updatebuffer (int pos, double value);

//DESTRUCTOR
//~Neuron();	
};


#endif
