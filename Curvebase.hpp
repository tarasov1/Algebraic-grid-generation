#ifndef CURVEBASE_HPP 
#define CURVEBASE_HPP

#include <iostream>
#include <cmath> 

using namespace std;

class Curvebase {

	protected:

		double pmin; 
		double pmax; 
		int   rev;
		double length;
		bool isStraigth;
 
		virtual double xp(double p) = 0;
		virtual double yp(double p) = 0;
		virtual double dxp(double p) = 0;
		virtual double dyp(double p) = 0;

		double fdx(double p);

		double integrate(double a, double b); 
		double ASI(double a, double b, double tol, double (Curvebase::*f)(double));
	 	double newtonsMethod(double s);
	 	double len();
	 	
	public:

		Curvebase(); 

		double x(double s);
    	double y(double s);

    	int getOrientation();
};

#endif 
