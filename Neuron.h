#pragma once
#include <vector>

class Neuron {

private:
	std::vector<double> weights;

public:
	Neuron ( int wightSize );
	std::vector<double> getWeights ( );
	void setWeight ( int index, double value );
	void setWeightMat ( std::vector<double> newWeights );
};

