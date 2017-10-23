#include "network_2.hpp"
#include <random>




using namespace std;

Network::Network(Neuron a, Neuron b)
:alpha_(a), beta_(b)
{}

double Network::getGlobalTime()
{
	return global_time_;
}
int Network::compteur(int i)
{
	return i;
}

int Network::simulation(double tstart, double tstop, double I) 
{
	global_time_ = tstart;

	ofstream myfile;
	ofstream myfile2;
	myfile.open ("neurontest.txt");				
	myfile2.open ("neurontest2.txt");
	
	int compteur(0);
	

	while((global_time_*alpha_.getH()) < tstop) 
	{


//in the same time update alpha_ et ask if it spiked
//-->if;update beta_ buffer's current position + delay value
		if(alpha_.update(I))
		{
			//cout<< global_time_<<endl;
			++compteur;
			beta_.updatebuffer((beta_.getInternalTime() + alpha_.getDelay()) % (alpha_.getDelay()+1), alpha_);
		}
		
//same for beta_
		if(beta_.update(0)) 
		{
			alpha_.updatebuffer((alpha_.getInternalTime() + beta_.getDelay()) % (beta_.getDelay()+1), beta_);
		}
		
//increase global_time_ of simulation

		global_time_ += 1 ;
//write potentials into ofstream myfiles.txt
		myfile << alpha_.getMembpot()<<endl;
		myfile2 << beta_.getMembpot()<<endl;
	}
//return total of spikes for both neurons
	//cout<< alpha_.getNbSpikes()<<endl;
	//cout<< beta_.getNbSpikes()<<endl;

//close ofstream
	myfile.close();
	myfile2.close();
	
	return compteur;
}

void Network:: addNeuron()
{
	network_.push_back(new Neuron(15, 0.1));
}
void Network::set_connectivity()
{
	for (size_t i(0); i< nb_exitatory; ++i)
	{
		addNeuron();
		network_[i]->setEx(true);
	}
	for (size_t i(nb_exitatory+1); i<network_.size(); ++i)
	{
		addNeuron();
		network_[i]->setEx(false);
	}
	
	for (size_t i = 0; i < network_.size(); i++)
	{
		random_device rd;
		mt19937 gen(rd());
		for (int j = 0; j < CE_; j++)
		{
			uniform_int_distribution<int> d(0,nb_exitatory-1);
			c_table_[i][d(gen)]+=1; 
		}
		for (int j = 0; j < CI_ ; j++)
		{
			uniform_int_distribution<int> d(nb_exitatory, network_.size());
			c_table_[i][d(gen)]+=1;
		}	
	}
}
