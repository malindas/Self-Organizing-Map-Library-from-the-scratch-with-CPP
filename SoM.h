#pragma once
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include "Neuron.h"
#include "vectorMath.h"


class SoM {
private:
	std::vector<Neuron> layer;
	std::vector<std::vector<double>> Samples;
	std::map<double,int> cost;  // <index, Euclidean Distance>
	std::map<int,double> minCosts; // Holds the minimum costs in a radius
	double learningRate; // learningRate
	int radius; // Radius
	int mapSize;
	void getMinCost ( ); // Calculates the minimum costs
	void SoM::UpdateWeights ( std::vector<double> currentSample );


public:
	SoM ( std::vector<std::vector<double>> Samples,
		  bool isColumn,
		  int mapSize,
		  int radius = 1,
		  double learningRate = 0.05 );
	 
	void trainSoM ( int numEpochs );
	void printToConsole ( );

};