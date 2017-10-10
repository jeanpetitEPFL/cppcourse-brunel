#include <iostream>
#include<vector>
#include<string> 
#include "neuron.cpp"
#include "neuron.hpp"


class Network : private vector<Neuron*>
{
public:

	void ajouter_neuron()
		{
			 push_back(new Neuron ());
		}

		
	void recieve(Neuron& b, Neuron& a)
{
		if (a.getSpikesTime().empty())
		{
			b.setMembPot(b.getMembpot());
		}	
		else {
			double New;
			size_t x;
			x= a.getSpikesTime().size()-1;
			if(a.getSpikesTime()[x]== b.getInternalTime())
			{ New+=0.4; }	
			b.setMembPot(b.getMembpot()+New);	
		}
}
	void update(double I)
		{
			for (int i(0); i < size(); ++i)
				(*this)[i]->update(I);
		}
	
	void vider()
		{
				for (int i(0); i < size(); ++i)
					delete (*this)[i];
				clear();
		}
~Network(){}
};
