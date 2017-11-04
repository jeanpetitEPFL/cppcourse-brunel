
#include "network_2.hpp"
  
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	/**
	Network needs number of exitatory neurons,
	number of inhibitory neurons
	Simulation needs Tstart, Tstop, 
	internal current I, g(which is Vext/Vthre)
	*/
	
	Network brain(10000, 2500);	
	brain.simulation(0,1000, 0, 5, 2);
	
	
	return 0;
}
