#include "Neuron.h"

Neuron::Neuron ( int weightSize )
{

	for (int i = 0; i < weightSize; i++) {
		this->weights.push_back ( (double)(rand ( ) % 100) );
	}
}

std::vector<double> Neuron::getWeights ( )
{
	return this->weights;
}

void Neuron::setWeightMat ( std::vector<double> newWeights )
{
	if (newWeights.size ( ) != this->weights.size())
		exit ( -1 );

	this->weights = newWeights;


}
