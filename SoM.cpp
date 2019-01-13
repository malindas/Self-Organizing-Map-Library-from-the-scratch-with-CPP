#include "SoM.h"

void SoM::getMinCost ( )
{
	// Clearing placeholders
	this->cost.clear ( );
	this->minCosts.clear ( );


	/* Calculating the Euclidean Distances */
	for (int i = 0; i < (int)this->layer.size ( ); i++) {
		std::vector<double> x = this->layer[i].getWeights ( );
		std::vector<double> y = this->Samples[i];
		this->cost.insert ( std::pair<double,int> (x * y,i) );

	}

	/* Taking minimum costs in a radius */
	auto it = cost.begin ( );
	if (radius >= (int)cost.size ( )) {	
			this->minCosts.insert ( std::pair<int, double> ( it->second, it->first ) );
	}
	else {
		for (int i = 0; i <= this->radius; i++) {
			this->minCosts.insert ( std::pair<int, double> ( it->second, it->first ) );
			it++;
		}
	
	}

	
}

void SoM::UpdateWeights (std::vector<double> currentSample)
{
	
	/* ---------------------------------------------------------
		Updating the Weights 
		W(new) = W(old) + (learningRate/radius +1) (x - W(old))
	------------------------------------------------------------*/
	auto mc_it = this->minCosts.begin ( );
	for (int r = 0; r <= this->radius; r++) {
		this->layer[mc_it->first].setWeightMat( this->layer[mc_it->first].getWeights ( ) +
			((this->learningRate / (double)(r + 1)) *
			(currentSample - this->layer[mc_it->first].getWeights ( ))));
	}

}

SoM::SoM ( std::vector<std::vector<double>> Samples, bool isColumn, int mapSize,int radius,double learningRate )
{
	// Saving the Dataset
	this->Samples = Samples;
	
	// Updating private Variables
	this->learningRate = learningRate;
	this->radius = radius;
	this->mapSize = mapSize;

	// Creating the Layer
	switch (isColumn) {
	case true: // Taking Columns as Feature vectors
		for (int i = 0; i < (mapSize * mapSize);i++) {
			this->layer.push_back ( Neuron ( Samples[0].size ( ) ) );
		}
		break;
	case false:// Taking Rows as Feature vectors
		for (int i = 0; i < (mapSize * mapSize);i++) {
			this->layer.push_back ( Neuron ( Samples.size ( )) );
		}
		break;
	}

	
}

void SoM::trainSoM ( int numEpochs )
{
	/*
		1. Load dataSample
		2. Get Euclidean Distances (Cost)
		3. Select minimum Cost
		4. Update weights
		5. repeat
	*/

	for (int i = 0; i < numEpochs; i++){
		std::cout << "Epoch:: " << i << std::endl;
		int sampleIdx = 0;
		while (sampleIdx != this->Samples.size ( )) {
			getMinCost ( );
			UpdateWeights ( this->Samples[i] );		
			sampleIdx++;
		}
		this->printToConsole ( );
	}

}


/* Print the neuron weights to the console */
void SoM::printToConsole ( )
{
	int i = 0;
	for (int r = 0; r < this->mapSize; r++) {
		for (int c = 0; c < this->mapSize; c++) {
			std::cout << "[";
			for (int j = 0; j < Samples[0].size ( ); j++) {
				std::cout << (this->layer[i].getWeights ( ))[j] << ", ";
			}
			i++;
			std::cout << "]";
		}
		std::cout << std::endl;
	}

}
