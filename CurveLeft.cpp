#include "CurveLeft.hpp"

CurveLeft::CurveLeft(double a, double b, double x) : fixedX(x) {
	pmin = a; 
	pmax = b;
	isStraigth = true; 
	length = len();
	rev = false; 
}

double CurveLeft::xp(double p) {
	return fixedX;
}

double CurveLeft::yp(double p) {
	return p;
}

double CurveLeft::dxp(double p) {
	return 0.;
}

double CurveLeft::dyp(double p) {
	return 1.;
}
