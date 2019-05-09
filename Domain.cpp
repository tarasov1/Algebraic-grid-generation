#include "Domain.hpp"

Domain::Domain (Curvebase &c0, Curvebase &c1, Curvebase &c2, Curvebase &c3) {
	curves[0] = &c0; 
	curves[1] = &c1;
	curves[2] = &c2; 
	curves[3] = &c3;

	
	if (!isConsistent()) {
		for (int i = 0; i < 4; i++) curves[i] = NULL;
	}

	m_ = n_ = 0; 
}

bool Domain::isConsistent() {
	bool check = true; 
	double tol = 10e-5; 

	if (fabs(curves[0] -> x(1) - curves[1] -> x(0)) > tol || fabs(curves[0] -> y(1) - curves[1] -> y(0)) > tol) check = false; 
	if (fabs(curves[1] -> x(1) - curves[2] -> x(1)) > tol || fabs(curves[1] -> y(1) - curves[2] -> y(1)) > tol) check = false;
	if (fabs(curves[2] -> x(0) - curves[3] -> x(1)) > tol || fabs(curves[2] -> y(0) - curves[3] -> y(1)) > tol) check = false;
	if (fabs(curves[3] -> x(0) - curves[0] -> x(0)) > tol || fabs(curves[3] -> y(0) - curves[0] -> y(0)) > tol) check = false; 

	return check;
}

void Domain::generateGrid(int m, int n) {
	if (m < 0 || n < 0) return;
    
    m_=m;
    n_=n;

    x_ = new double[m_*n_];
    y_ = new double[m_*n_];

    double eta = 1.0/(m-1);
    double xi = 1.0/(n-1);

       for (int i = 0; i < m_; i++) {
           for (int j = 0; j < n_; j++) {

                x_[i*n_+j] = Eta(i*eta)*curves[3]->x(T(j*xi)) + 
                             Xi(i*eta)*curves[1]->x(T(j*xi)) + 
                             Eta(T(j*xi))*curves[0]->x(i*eta) + 
                             Xi(T(j*xi))*curves[2]->x(i*eta) - 
                             Eta(i*eta)*Eta(T(j*xi))*curves[3]->x(0) - 
                             Xi(i*eta)*Eta(T(j*xi))*curves[1]->x(0) - 
                             Eta(i*eta)*Xi(T(j*xi))*curves[3]->x(1) - 
                             Xi(i*eta)*Xi(T(j*xi))*curves[1]->x(1);

                y_[i*n_+j] = Eta(i*eta)*curves[3]->y(T(j*xi)) + 
                             Xi(i*eta)*curves[1]->y(T(j*xi)) + 
                             Eta(T(j*xi))*curves[0]->y(i*eta) + 
                             Xi(T(j*xi))*curves[2]->y(i*eta) - 
                             Eta(i*eta)*Eta(T(j*xi))*curves[3]->y(0) - 
                             Xi(i*eta)*Eta(T(j*xi))*curves[1]->y(0) - 
                             Eta(i*eta)*Xi(T(j*xi))*curves[3]->y(1) - 
                             Xi(i*eta)*Xi(T(j*xi))*curves[1]->y(1);
            }
       }
            
}


double Domain::Eta(double x) {
	return 1-x;
}

double Domain::Xi(double x) {
	return x;
}

double Domain::T(double sigma) {
    return (1 + tanh(3*(sigma - 1))/tanh(3));
}


bool Domain::writeToFile() {
	FILE *fp;
	fp =fopen("AlgebraicGrid.bin","wb");
	fwrite(&n_,sizeof(int),1,fp);
	fwrite(&m_,sizeof(int),1,fp);
	fwrite(x_,sizeof(double),(n_*m_),fp);
	fwrite(y_,sizeof(double),(n_*m_),fp);
	fclose(fp);

	std::cout<<"Grid is written to AlgebraicGrid.bin"<<std::endl; 

	return true;
}




