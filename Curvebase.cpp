#include "Curvebase.hpp"

Curvebase::Curvebase() {

}
 
double Curvebase::fdx(double p) {
    return sqrt(dxp(p)*dxp(p)+dyp(p)*dyp(p));
} 

double Curvebase::integrate(double a, double b) { 
    if (isStraigth)return (b-a); 
    else {
        double (Curvebase::*f)(double); 
        f = &Curvebase::fdx; 
        return ASI(a, b, 10e-8, f);
    }
}

int Curvebase::getOrientation() {
    return rev;
}

double Curvebase::x(double s) {
    if (!isStraigth) return xp(newtonsMethod(s));
    else if(isStraigth) return xp(pmin + s*length);
    else return 0.;
}

double Curvebase::y(double s) {
    return yp(newtonsMethod(s));
}

double Curvebase::len() {
    return integrate(pmin, pmax); 
}

double Curvebase::ASI(double a, double b, double tol, double (Curvebase::*f)(double)) {
    double c = (a+b)/2; 
    double I1 = (b - a)*(fdx(a) + 4*fdx(c) + fdx(b))/6; 
    double I2 = (c - a)*(fdx(a) + 4*fdx((c+a)/2) + fdx(c))/6 + (b - c)*(fdx(c) + 4*fdx((c+b)/2) + fdx(b))/6; 
    double errest = fabs(I2-I1); 
    
    if (errest < 15*tol) return I2; 

    return ASI(a, c, tol/2, f) + ASI(c, b, tol/2, f);
}
 
double Curvebase::newtonsMethod(double s) {
    double p0, p1;
    double tol = 10e-8;
    double error = 0.;

    p1 = pmin*(1-s)+s*pmax;

    while (error > tol) {
        p0 = p1;
        p1 = p0-(integrate(pmin, p0)-s*length)/(dxp(p0)*dxp(p0)+dyp(p0)*dyp(p0));
        error = fabs(p1-p0);
    }

    return p1;
}

