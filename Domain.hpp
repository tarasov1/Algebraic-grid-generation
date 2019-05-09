#ifndef DOMAIN_HPP 
#define DOMAIN_HPP

#include <iostream>
#include <math.h>
#include <cstdio>

#include "Curvebase.hpp"

class Domain {

		Curvebase *curves[4];

		int m_, n_; 
		double *x_, *y_;

		bool isConsistent();
		double Eta(double x);
		double Xi(double x);
		double T(double sigma);

	public:

		Domain(Curvebase&, Curvebase&, Curvebase&, Curvebase&);

		void generateGrid(int m, int n);
		bool writeToFile();
		 
}; 

#endif  