#include "neuron.hpp"
#include "neuron.cpp"
#include <fstream>
#include <iostream>
using namespace std;


void simulation (Neuron& a)
	{	
		double I (100);
		ofstream myfile;
		myfile.open ("neurontest.txt");
		double simtime(0.0);
		double tstop (10);
		while (simtime < tstop)
		{
			a.update(I);
			myfile << a.getMembpot()<<endl;
			simtime+=a.getH();
		}
	cout<< a.getNbSpikes()<<endl;
	myfile.close();
	}	


int main()
{
	Neuron a;
	
	simulation(a);
	
	
	
	return 0;
}
