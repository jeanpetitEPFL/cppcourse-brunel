#include "network_2.hpp"





using namespace std;

Network::Network(Neuron a, Neuron b)
:alpha_(a), beta_(b)
{}

double Network::getGlobalTime()
{
	return global_time_;
}


void Network::simulation(double tstart, double tstop, double I) {

	global_time_ = tstart;

	ofstream myfile;
	ofstream myfile2;
	myfile.open ("neurontest.txt");				
	myfile2.open ("neurontest2.txt");

	

	while(global_time_ < tstop) {

		alpha_.update(I);

		if(alpha_.ifPotMaxReached()) 
		{
			beta_.updatebuffer((alpha_.getInternalTime() + alpha_.getDelay()) % 4);

		}
	
		beta_.update(0);

		if(beta_.ifPotMaxReached()) {

			alpha_.updatebuffer((beta_.getInternalTime() + beta_.getDelay()) % 4);

		}

		global_time_ += alpha_.getH() ;
		myfile << alpha_.getMembpot()<<endl;
		myfile2 << beta_.getMembpot()<<endl;


	}	
	cout<< alpha_.getNbSpikes()<<endl;
	cout<< beta_.getNbSpikes()<<endl;

	myfile.close();
	myfile2.close();

}
