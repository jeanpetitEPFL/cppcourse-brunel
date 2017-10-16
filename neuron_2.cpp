#include "neuron_2.hpp"


using namespace std;

Neuron::Neuron(int Delay, double J)
:delay_(Delay),J_(J)
{
	membrane_pot_=Vreset_;
	nb_spikes_=0.0;
	time_buffer_ = vector<double>((delay_+1),0);
//buffer vector size : delay+1
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
	
	int Neuron::getDelay()  const
	{
		return delay_;
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

	
//update the buffer time ;
//send an assert
//add J in the buffer's position chosen
	void Neuron::updatebuffer(int pos)
	{
		assert(pos<time_buffer_.size());
		time_buffer_[pos]+=J_;
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
			++ nb_spikes_;
			
			spikes_time_.push_back(internal_time_*h_);
			SetNewPot();
	}
	
//return if refractory time is over
	bool Neuron::Refractory()
	{
		if(internal_time_ *h_- spikes_time_.back()>= tau_ref_ )
		{ return true;}
	}
	
// set the increase of the potential 
// when the neuron is not in its refractory time

//+ add J from other neurons that spiked
//then clear the current buffer position	
	void Neuron::SetPot(double I)
	{
		double New;
		New = ((exp(-h_/tau_) * membrane_pot_)+ (I*R_*(1-exp(-h_/tau_))) + time_buffer_[internal_time_%(delay_+1)]);
		setMembPot(New);
		time_buffer_[internal_time_%(delay_+1)] =0.0;
	}
	
// set the potential at Vreset=0
// after a spike	
	void Neuron::SetNewPot()
	{
		double New;
		New= Vreset_;
		setMembPot(New);
	}
	
// update the neuron's potential every h time	
	bool Neuron::update (double const&  I)
	{
		internal_time_+=1;
		if (spikes_time_.empty())
		{
			SetPot(I);
			if(ifPotMaxReached())
			{
				PotMaxReached();
				return true;
			}
		}		
		else 
		{		
			if (Refractory() and !ifPotMaxReached()) //determine if refractory time is over and if membrane potential >=Vthreshold
			{
				SetPot(I);
			}
			
			if(ifPotMaxReached())
			{
				PotMaxReached();
				return true;
			}
		}
	}
	
