
#include "network_2.hpp"
  
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	Neuron a(2,4);
	Neuron b(3,4);
	Network alpha(a,b);
	
	alpha.simulation(0,200, 1.5);
	
	
	return 0;
}
