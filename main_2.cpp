
#include "network_2.hpp"
  
#include <fstream>
#include <iostream>
using namespace std;

int main()
{

	Network brain(10000, 2500);	
	brain.simulation(0,1000, 0);
	
	
	return 0;
}
