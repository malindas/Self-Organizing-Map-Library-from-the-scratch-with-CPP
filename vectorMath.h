#pragma once
#include <vector>


// Operator Overloads

inline double operator*( std::vector<double>& x, std::vector<double>& y ) {
	if (x.size ( ) != y.size ( ))
		exit ( -1 );
	double sum = 0;
	for (int i = 0; i < (int)x.size ( ); i++) {
		sum += x[i] * y[i];
	}
	return sum;
}


inline std::vector<double> operator+( std::vector<double>& x, std::vector<double>& y ) {
	if (x.size ( ) != y.size ( ))
		exit ( -1 );

	std::vector<double> ret;
	for (int i = 0; i < (int)x.size ( ); i++) {
		ret.push_back(x[i] + y[i]);
	}
	return ret;
}


inline std::vector<double> operator-( std::vector<double>& x, std::vector<double>& y ) {
	if (x.size ( ) != y.size ( ))
		exit ( -1 );

	std::vector<double> ret;
	for (int i = 0; i < (int)x.size ( ); i++) {
		ret.push_back ( x[i] - y[i] );
	}
	return ret;
}


inline std::vector<double> operator*( double Scalar, std::vector<double>& y ) {
	
	std::vector<double> ret;
	for (int i = 0; i < (int)y.size ( ); i++) {
		ret.push_back ( Scalar * y[i] );
	}
	return ret;
}

inline std::vector<double> operator+=( std::vector<double>& x, std::vector<double>& y ) {
	if (x.size ( ) != y.size ( ))
		exit ( -1 );

	return x = x + y;
}

