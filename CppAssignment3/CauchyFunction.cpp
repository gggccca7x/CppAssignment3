#define _USE_MATH_DEFINES

#include "CauchyFunction.h"
#include <cmath> 
#include <iostream>
#include <fstream>
#include <random>

CauchyFunction::CauchyFunction(std::string func, double high, double low)
	: m_StrFunction(func), m_LinearExtremeHigh(high), m_LinearExtremeLow(low)
{
}

CauchyFunction::~CauchyFunction()
{
}

double CauchyFunction::m_IntegtrateFunc(unsigned int numberOfValues)
{
	double sumTotal = 0;

	double highestX = m_LinearExtremeLow;
	double lowestX = m_LinearExtremeHigh;

	std::random_device rd;
	std::mt19937_64 mt(rd());

	std::uniform_real_distribution<double> dist(m_LinearExtremeLow, m_LinearExtremeHigh);

	for (unsigned int i = 0 ; i < numberOfValues; i++)
	{
		double randomX = dist(mt);

		if (randomX > highestX) {
			highestX = randomX;
		}
		if (randomX < lowestX) {
			lowestX = randomX;
		}

		//std::cout << "Random x : " << randomX << std::endl;

		double equation_f_x = m_Function(randomX);
		sumTotal += equation_f_x;
	}

	//std::cout << "Highest x: " << highestX << " , lowest x: " << lowestX << std::endl;
	double equationRange = highestX - lowestX;
	//std::cout << "Range : " << equationRange << std::endl;

	return equationRange * (sumTotal / numberOfValues);
}

double CauchyFunction::m_Function(double x)
{
	//f(x) = (pi(1 + x^2)) ^ -1
	return pow(M_PI * (1 + (x * x)),-1);
}

void CauchyFunction::m_Metropolis(std::string filename, unsigned int interator)
{
	std::random_device rd;
	std::mt19937_64 mt(rd());
	std::uniform_real_distribution<double> dist_n5_5(m_LinearExtremeLow, m_LinearExtremeHigh);
	std::uniform_real_distribution<double> dist_0_1(0, 1);

	//Generate a random number (x) on the range where the function is defined.
	double x1 = dist_n5_5(mt);
	double previousX = x1;

	std::ofstream myfile;
	myfile.open(filename);

	//iterative:
	for (unsigned int i = 0; i < interator; i++)
	{
		//generate a random number, y, from the uniform distribution
		double y = dist_n5_5(mt);

		//Compute A = min(f(y)/f(xt),1)
		double computeA = fmin(m_Function(y) / m_Function(previousX), 1);

		//Accept y with probability A
		double random_0_1 = dist_0_1(mt);
		if (random_0_1 < computeA)
		{
			//double y accepted
			previousX = y;
		}
		
		myfile << previousX << "\n";
	}

	myfile.close();

}
