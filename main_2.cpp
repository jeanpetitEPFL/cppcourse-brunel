
#include "network.hpp"
  
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	/**
	Network needs number of exitatory neurons,
	number of inhibitory neurons
	Simulation needs Tstart, Tstop, 
	internal current I, g and poisson
	if other paramters wanted, change them here
	*/
	
	Network brain(10000, 2500);	
	brain.simulation(0,1000, 0, -5, 2);
	
	
	return 0;
}
