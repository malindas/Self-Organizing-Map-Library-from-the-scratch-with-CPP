#include <iostream>
#include <vector>
#include "SoM.h"




int main ( ) {
	std::vector < std::vector<double>> Inputs;

	for (int i = 0; i < 100; i++) {
		std::vector<double> tmp;
		tmp.push_back ( (double)(rand ( ) % 20) );
		tmp.push_back ( (double)(rand ( ) % 80) );
		tmp.push_back ( (double)(rand ( ) % 88) );
		tmp.push_back ( (double)(rand ( ) % 90) );
		Inputs.push_back ( tmp );
	}

	SoM *smap = new SoM (Inputs, true, 5,2,0.2);
	smap->trainSoM (30);

	std::cin.get ( );
	return 0;
}