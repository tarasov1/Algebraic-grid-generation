#include "CurveRight.hpp"

CurveRight::CurveRight(double a, double b, double x) : fixedX(x) {
	pmin = a; 
	pmax = b;
	isStraigth = true; 
	length = len();
	rev = true;
}

double CurveRight::xp(double p) {
	return fixedX;
}

double CurveRight::yp(double p) {
	return p;
}

double CurveRight::dxp(double p) {
	return 0.;
}

double CurveRight::dyp(double p) {
	return 1.;
}
