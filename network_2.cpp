#include "network_2.hpp"

using namespace std;

Network::Network(int i, int j)
:c_table_(i, vector<int>(j,1))
{
	set_connectivity();
}

double Network::getGlobalTime()
{
	return global_time_;
}
int Network::compteur(int i)
{
	return i;
}

void Network::simulation(double tstart, double tstop, double I) 
{
	global_time_ = tstart;

	/*ofstream myfile;
	ofstream myfile2;
	myfile.open ("neurontest.txt");				
	myfile2.open ("neurontest2.txt");
	
	int compteur(0);
	* 
	*/
	//ofstream myfile;
	//myfile.open ("neurontest.txt");
	while((global_time_*network_[0]->getH()) < tstop) 
	{
		
		cout<<network_[10]->getMembpot()<<" "<<flush;
		
		//	myfile << network_[0]->getMembpot()<<" "<<flush;
		//cout << network_[1]->getMembpot()<<" "<<flush;
		
		
		for (size_t i = 0; i < network_.size(); i++)
		{
			//cout<< i <<" "<<flush;
			//cout<<network_[i]->getMembpot()<<" "<<flush;
			//	myfile << network_[i]->getMembpot()<<" "<<flush;
			if (network_[i]->update(I))
				{
					for (int j = 0; j <network_.size() ; j++)
					{	//cout<<network_[j]->getInternalTime()<< endl;
						//cout<<network_[i]->getDelay()<<endl;
						if (network_[i]->getEx())
						{
							network_[j]->updatebuffer((network_[i]->getInternalTime()+network_[i]->getDelay())%(network_[i]->getDelay()+1),c_table_[i][j]*5*network_[i]->getJ());
						}
						else
						{
							network_[j]->updatebuffer((network_[i]->getInternalTime()+network_[i]->getDelay())%(network_[i]->getDelay()+1),c_table_[i][j]*network_[i]->getJ());
						}
					}	
				}
	
		}
		global_time_ += 1 ;
	}
}	

	//myfile.close();

void Network:: addNeuron()
{
	network_.push_back(new Neuron());
	
}
void Network::set_connectivity()
{
	for (size_t i(0); i< nb_exitatory; ++i)
	{
		addNeuron();
		network_[i]->setEx(true);
	
	}
	for (size_t i(0); i<nb_inhibitory; ++i)
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
			uniform_int_distribution<> dis(0,nb_exitatory-1); 
			c_table_[i][dis(gen)]+=1; 
		}
		for (int j = 0; j < CI_ ; j++)
		{
			uniform_int_distribution<> d(nb_exitatory, network_.size());
			c_table_[i][d(gen)]+=1;
		}	
	}

}

Network::~Network()
{
	for (int i = 0; i < network_.size(); i++)
	{
		network_[i]=nullptr;
		delete network_[i];
	}
	
}
