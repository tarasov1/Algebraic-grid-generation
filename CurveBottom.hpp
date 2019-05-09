#ifndef CURVEBOTTOM_HPP
#define CURVEBOTTOM_HPP

#include "Curvebase.hpp"

#include <cmath> 

using namespace std;

class CurveBottom : public Curvebase {

			//double midPt;
			double xp(double p) override; 
			double yp(double p) override; 
			double dxp(double p) override; 
			double dyp(double p) override;
		

		public:

			CurveBottom(double a, double b);  
	}; 

#endif 