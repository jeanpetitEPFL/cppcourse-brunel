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

		//alpha_.update(I);

		if(alpha_.update(I)) 
		{
			beta_.updatebuffer((beta_.getInternalTime() + alpha_.getDelay()) % 16);

		}
	
		//beta_.update(0);

		if(beta_.update(0)) {

			alpha_.updatebuffer((alpha_.getInternalTime() + beta_.getDelay()) % 16);

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
