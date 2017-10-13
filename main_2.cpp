
#include "network_2.hpp"
  
#include <fstream>
#include <iostream>
using namespace std;
/*
void ifneverspiked(Neuron& a, Neuron& b)
{
	if (a.getSpikesTime().empty())
		{
			b.setMembPot(b.getMembpot());
		}	
}

void ifalreadyspiked(Neuron& a, Neuron& b)
{
if(!a.getSpikesTime().empty())		
		{
			double New;
			size_t x;
			x= a.getSpikesTime().size()-1;
			if(a.getSpikesTime()[x]== b.getInternalTime())
			{ 
				b.setbuffer();
				//New+=0.4; 
				
			}
			//New=b.getbuffer()[3];	
			//b.setMembPot(b.getMembpot()+New);	
			b.updatebuffer();
		}
	
}

void recieve(Neuron& b, Neuron& a)
{
		ifneverspiked(a,b);
		ifalreadyspiked(a,b);
		
}


void simulation (Neuron& a, Neuron& b)
	{	
		double I (1.5);
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
*/
int main()
{
	Neuron a(2,0.4);
	Neuron b(3,0.4);
	Network alpha(a,b);
	
	alpha.simulation(0,200, 1.5);
	
	
	return 0;
}
