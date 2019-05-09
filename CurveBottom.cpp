#include "CurveBottom.hpp"

CurveBottom::CurveBottom(double a, double b) { 
    pmin = a; 
    pmax = b;
	isStraigth = false;
	length = len();
	rev = true;
}

double CurveBottom::xp(double p) {
    return p;
}
 
double CurveBottom::yp(double p) {
    if ((p >= -10) && (p < -3)) return (1./(2*(1 + exp(-3.*(p + 6)))));
    if ((p >= -3) && (p <= 5)) return (1./(2*(1 + exp(3.*p))));
    return 0.;
}

double CurveBottom::dxp(double p) {
    return 1.;
}

double CurveBottom::dyp(double p) {
    double help_var;

    if ((p >= -10) && (p < -3)) {
       help_var = exp(-3.*(p + 6));
        return (3*help_var/(2*(help_var + 1)*(help_var + 1)));
    }

    if ((p >= -3) && (p <= 5)) {
        help_var = exp(3.*p);
        return (-3*help_var/(2*(help_var + 1)*(help_var + 1)));
    }
    return 0.;
}
