
#include "network_2.hpp"
  
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	
	
	Network alpha(12500, 12500);
	
	alpha.simulation(0,100, 1.01);
	
	
	return 0;
}
