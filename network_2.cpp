#include "network_2.hpp"





using namespace std;

Network::Network(Neuron a, Neuron b)
:alpha_(a), beta_(b)
{}

double Network::getGlobalTime()
{
	return global_time_;
}


void Network::simulation(double tstart, double tstop, double I) 
{
	global_time_ = tstart;

	ofstream myfile;
	ofstream myfile2;
	myfile.open ("neurontest.txt");				
	myfile2.open ("neurontest2.txt");

	

	while((global_time_*alpha_.getH()) < tstop) 
	{


//in the same time update alpha_ et ask if it spiked
//-->if;update beta_ buffer's current position + delay value
		if(alpha_.update(I))
		{
			beta_.updatebuffer((beta_.getInternalTime() + alpha_.getDelay()) % (alpha_.getDelay()+1));
		}
		
//same for beta_
		if(beta_.update(0)) 
		{
			alpha_.updatebuffer((alpha_.getInternalTime() + beta_.getDelay()) % (beta_.getDelay()+1));
		}
		
//increase global_time_ of simulation

		global_time_ += 1 ;
//write potentials into ofstream myfiles.txt
		myfile << alpha_.getMembpot()<<endl;
		myfile2 << beta_.getMembpot()<<endl;
	}
//return total of spikes for both neurons
	cout<< alpha_.getNbSpikes()<<endl;
	cout<< beta_.getNbSpikes()<<endl;

//close ofstream
	myfile.close();
	myfile2.close();

}
