#include <neuron.hpp>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

	void Neuron::setMembPot(double m)
	{
		membrane_pot_= m;
	}
	void Neuron::setNbSpikes (int nbs)
	{
		nb_spikes_=nbs;
	}
	/*void Neuron::setTime (vector <double> t)
	{
		
	}
	*/
	
	double Neuron::getMembpot()
	{
		return membrane_pot_;
	}
	
	int Neuron::getNbSpikes()
	{
		return nb_spikes_;
	}
	
	vector<double> Neuron::getSpikesTime()
	{
	}
	
	void Neuron::update(double& h, double& I)
	{
		internal_time_+=h;
		if (internal_time_ - spikes_time_.end()>= tau_ref_)
		{
			double new;
			new = exp(-h_/tau_) *membrane_pot_+ I*R(1-exp(-h_/tau_));
		
			setMembPot(new);
			if (membrane_pot_>= POTENTIELMAX)
			{
				//setMembPot(POTENTIELMAX); ????
				++ nb_spikes_;
				spikes_time_.pushback(internal_time_);
			}
		}
		else 
		{
			double new;
			new=exp(-h_/tau_) *membrane_pot_;
			setMembPot(new);
		 }
		
		// ou alors si on définit un attribut bool refrectory
		/*
		 * if (refractory_==true)
		 * {
		 * 	setMembPot(0);
		 * } else 
		 * {
		 * double new;
		 * new = exp(-h_/tau_) *membrane_pot_+ I*R(1-exp(-h_/tau_));
		 * setMembPot(new);
		 * }
		 *
		 */			
	}
	
	Neuron::Neuron(c, t, tr, v, h)
	:C_(c), tau_(t), tau_ref_(tr),Vreset_(vr), h_(h)
	{}
	
	Neuron::Neuron()
	:C_(250), tau_(10), tau_ref_(2), Vreset_(-70),h_(0.1)
	{}
	
	Neuron::~Neuron()
	{}
