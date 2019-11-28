#include <iostream>
#include <string>
#include "CauchyFunction.h"
#include "cauchy_test.h"

int main()
{
	CauchyFunction c("", 5, -5);

	std::string fileName = "metropolis.csv";

	//20_000_000
	std::cout << c.m_IntegtrateFunc(20000000) << std::endl;
	c.m_Metropolis(fileName, 500000);

	CreateHistogramFile(fileName, -5, 5);
}