
#include "network_2.hpp"
  
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	Neuron a(15,0.4); //delay  ms, J=0.4 mV
	Neuron b(15,0.4);
	Network alpha(a,b);
	
	alpha.simulation(0,200, 1.01);
	
	
	return 0;
}
