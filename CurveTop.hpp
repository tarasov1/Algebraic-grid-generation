#ifndef CURVETOP_HPP
#define CURVETOP_HPP

#include "Curvebase.hpp"

#include <cmath> 

using namespace std;

class CurveTop : public Curvebase {

			double fixedY;
			double xp(double p) override; 
			double yp(double p) override; 
			double dxp(double p) override; 
			double dyp(double p) override;

		public:

			CurveTop(double a=0.0, double b=0.0, double fixedY=0.0); 
			 
	}; 

#endif 