#include "neuron.hpp"
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <fstream>

using namespace std;

// SETTERS	
	void Neuron::setMembPot(double m)
	{
		membrane_pot_= m;
	}
	void Neuron::setNbSpikes (int nbs)
	{
		nb_spikes_=nbs;
	}
// GETTERS	
	double Neuron::getMembpot()
	{
		return membrane_pot_;
	}
	
	int Neuron::getNbSpikes()
	{
		return nb_spikes_;
	}
	double Neuron::getH()
	{
		return h_;
	}
	
// determine if the potential max is reached
// and if, push into spiketime the internal time of the neuron.	
	void Neuron::ifPotMaxReached()
	{
		if (membrane_pot_>= Vthreshold_)
		{
			++ nb_spikes_;
			spikes_time_.push_back(internal_time_);
		}
	}
// set the increase of the potential 
// when the neuron is not in its refractory time	
	void Neuron::SetPot(double I)
	{
		double New;
		New = ((exp(-h_/tau_) * membrane_pot_)+ (I*R_*(1-exp(-h_/tau_))));
		
		setMembPot(New);

	}
// set the potential at Vreset=0
// after a spike	
	void Neuron::SetNewPot()
	{
		double New;
		New= Vreset_;
		setMembPot(New);
	}
//recieve J from an other neuron when threshold depassed
void Neuron::recieve(Neuron& a)
{
		if (a.spikes_time_.empty())
		{
			setMembPot(getMembpot());
		}	
		else {
			double New;
			size_t x;
			x= a.spikes_time_.size()-1;
			if(a.spikes_time_[x]== internal_time_)
			{ New+=0.4; }	
			setMembPot(getMembpot()+New);	
		}		
}
// update the neuron's potential every h time	
	void Neuron::update (double I, Neuron& a)
	{
		internal_time_+=h_;
		
		if (spikes_time_.empty())
		{
			
			SetPot(I);
			
			ifPotMaxReached();
			
			recieve(a);
		}		

		else 
		{		
			if (internal_time_ - spikes_time_.back()>= tau_ref_) //determine if refractory time is over
			{
				SetPot(I);
				
				ifPotMaxReached();
				
				recieve (a);
			}
			else 
			{
				SetNewPot();
			}
		 
		}
	}
	
// CONSTRUCTORS	
	Neuron::Neuron(double c,double t,double tr,double v, double vt, double h,double r)
	:C_(c), tau_(t), tau_ref_(tr),Vreset_(v), Vthreshold_(vt), h_(h), R_(r)
	{
		membrane_pot_=Vreset_;
		nb_spikes_=0.0;
	}
	
	Neuron::Neuron()
	:C_(1), tau_(20.0), tau_ref_(2.0), Vreset_(0.0),Vthreshold_(20.0), h_(0.1), R_(20.0)
	{
		membrane_pot_=Vreset_;
		nb_spikes_=0.0;

	}
// DESTRUCTORS	
	Neuron::~Neuron()
{}
