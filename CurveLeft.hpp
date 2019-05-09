#ifndef CURVELEFT_HPP
#define CURVELEFT_HPP

#include "Curvebase.hpp"

#include <cmath> 

using namespace std;

class CurveLeft : public Curvebase {

			double fixedX;
			double xp(double p) override; 
			double yp(double p) override; 
			double dxp(double p) override; 
			double dyp(double p) override;
			

		public:

			CurveLeft(double a=0.0, double b=0.0, double fixedX=0.0);

	}; 

#endif 