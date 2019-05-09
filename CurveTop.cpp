#include "CurveTop.hpp"

CurveTop::CurveTop(double a, double b, double y) : fixedY(y) {
	pmin = a; 
	pmax = b;
	isStraigth = true; 
	length = len();
	rev = false;
}

double CurveTop::xp(double p) {
	return p;
}

double CurveTop::yp(double p) {
	return fixedY;
}

double CurveTop::dxp(double p) {
	return 1.;
}

double CurveTop::dyp(double p) {
	return 0.;
}
