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

#include "neuron.hpp"


using namespace std;
//CONSTRUCTOR
Neuron::Neuron()
{
	membrane_pot_=Vreset_;
	nb_spikes_=0.0;
	
	//buffer vector size : delay+1
	time_buffer_ = vector<double>((delay_+1),0);


	
}

//method used in Network class
void Neuron::connect(int i)
{
	connections_.push_back(i);
}
	
// GETTERS	
double Neuron::getMembpot() const 
{
	return membrane_pot_;
}

int Neuron::getNbSpikes() const
{
	return nb_spikes_;
}
double Neuron::getH() const
{
	return h_;
}
	
int Neuron::getInternalTime() const
{
	return internal_time_;
}
	
vector<double> Neuron::getSpikesTime() 
{
	return spikes_time_;
}
	
double Neuron::getLastTimeSpike()
{
	return spikes_time_.back();		
}
	
int Neuron::getDelay()  const
{
	return delay_;
}
	
bool Neuron::getEx()
{
	return E_;
}
	
double Neuron::getJ()
{
	return J_;
}

	
vector<int> Neuron::getConnections()
{
	return connections_;
}
// SETTERS	
void Neuron::setMembPot(double m)
{
	membrane_pot_= m;
}
	
void Neuron::setNbSpikes (int nbs)
{
	nb_spikes_=nbs;
}

void Neuron::setEx (bool alpha)
{
	E_ = alpha;
}


//update the buffer time ;
//send an assert
//add J in the buffer's position chosen
void Neuron::updatebuffer(int pos, double value)
{
	//assert(pos<=time_buffer_.size());
	time_buffer_[pos]+=value; 
}
	
	
// determine if the potential max is reached
// and if, push into spiketime the internal time of the neuron.	
bool Neuron::ifPotMaxReached()
{
	if (membrane_pot_>= Vthreshold_)
	{ return true; } 
	else 
	{ return false; }
}

//when Vthreshold reached, add internal time into the spikestime vector
//then set the membrane potential to Vreset 
void Neuron::PotMaxReached ()
{
	nb_spikes_+=1;
	spikes_time_.push_back(internal_time_*h_);
	SetNewPot();		
}
	
//return yes if refractory time is over 
bool Neuron::Refractory()
{
	if(internal_time_ *h_- spikes_time_.back()>= tau_ref_ )
	{ return true;}
	else {return false;}
}
	
	
void Neuron::SetPot(double I, int pois)
{
	double New;
	
	
	//set the increase of the potential 
	//when the neuron is not in its refractory time
	//add signal from other neurons that spiked and the background noise
	New = 	((exp(-h_/tau_) * membrane_pot_) 
			+(I*R_*(1-exp(-h_/tau_)))
			+ time_buffer_[internal_time_%(delay_+1)] 
			+pois*0.1);
				
	setMembPot(New);
	
	//clear the current buffer position
	time_buffer_[internal_time_%(delay_+1)] =0.0;
}
	
// set the potential at Vreset=0 after a spike	
void Neuron::SetNewPot()
{
	double New;
	New= Vreset_;
	setMembPot(New);
	
	//clear the current buffer position
	time_buffer_[internal_time_%(delay_+1)] =0.0;
}
	
// update the neuron's potential every h time	
bool Neuron::update (double const&  I, int pois)
{
	bool h;
	
	//if never spiked -> increase potential
	if (spikes_time_.empty())
	{
		SetPot(I, pois);
		
		//check if potential >=Vthreshold
		if(ifPotMaxReached())
		{
			internal_time_+=1;
			PotMaxReached();
			
			h= true;
		}
	}		
	else 
	{	
		//check if refractory time is not over
		if(!Refractory()) 
		{SetNewPot();}
		
		//check if refractory time is over
		//and if membrane potential >=Vthreshold
		if ((Refractory()) and (!ifPotMaxReached())) 
		{
			SetPot(I, pois);
		}
		
		//check if potential >=Vthreshold	
		if(ifPotMaxReached())
		{
			internal_time_+=1;
			PotMaxReached();
			h= true;
		}
	}
	
	internal_time_+=1;
	return h;
}	

