#include "neuron.hpp"
#include "neuron.cpp"
#include <fstream>
#include <iostream>
using namespace std;

/*
void simulation (Neuron& a)
	{	
		double I (1);
		ofstream myfile;
		myfile.open ("neurontest.txt");
		double simtime(0.0);
		double tstop (1000);
		while (simtime < tstop)
		{
			a.update(I);
			myfile << a.getMembpot()<<endl;
			simtime+=a.getH();
		}
	cout<< a.getNbSpikes()<<endl;
	myfile.close();
	}	
	*/
	
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
void simulation (Neuron& a, Neuron& b)
	{	
		double I (10);
		ofstream myfile;
		ofstream myfile2;
		myfile.open ("neurontest.txt");		
		myfile2.open ("neurontest2.txt");

		double simtime(0.0);
		double tstop (200);
		while (simtime < tstop)
		{
			a.update(I);
			b.update(0);
			recieve(b,a);
			recieve(a,b);
			myfile << a.getMembpot()<<endl;
			myfile2 << b.getMembpot()<<endl;

			simtime+=a.getH();
		}
	cout<< a.getNbSpikes()<<endl;
	cout<< b.getNbSpikes()<<endl;

	myfile.close();
	myfile2.close();
	}	


int main()
{
	Neuron a;
	Neuron b;
	
	simulation(a,b);
	
	
	
	return 0;
}
