#include "include/solver.h"


std::vector<double> SolveBICG(std::vector<double> p0,std::vector<double> b)
{
	int size = (int)b.size();
	
	std::vector<double> residual(size,0), _residual(size,1.0), p(size,0), z(size,0),s(size, 0), w(size,0);

	int maxIt(10000), iter(0);
	double precision(1e-6), normResidual(0), alpha(0), omega(0), beta(0);

	// Temporary variables to avoid computing several times the same expression
	double temp(0), temp2(0), temp3(0);   

	residual = b - BBT(p0);
	_residual = residual;
	p = residual;
	normResidual = norm(residual);
	temp2 = ps(residual, _residual);

	while (iter <= maxIt && normResidual > precision)
	{
		z = BBT(p);
		temp = temp2;
		alpha = temp / ps(z, _residual);
		s = residual - alpha * z ;
		w = BBT(s);
		omega = ps(w,s)/ps(w,w);
		p0 = p0 + alpha * p + omega * s ;
		residual = s - omega * w ;
		temp2 = ps(residual, _residual);
		beta = (temp2/temp) * (alpha/omega);
		p = residual + beta*(p - omega*z) ;

		normResidual = norm(residual);
		iter++;

	}

	if (iter > maxIt)
		std::cout << "precision not reached yet. residual norm = " <<normResidual<< std::endl;
	
    return p0;
}


// EUCLIDIAN SCALAR PRODUCT 
double ps(std::vector<double> X, std::vector<double> Y)
{
	int size = (int)X.size();
	double result(0);
		for (int i = 0; i < size; ++i)
			result += X[i] * Y[i];
	return result;
}

//EUCLIDIAN NORM
double norm(std::vector<double> X)
{
	return sqrt(ps(X, X));
}
