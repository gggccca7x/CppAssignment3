#pragma once

#include <string>

class CauchyFunction
{
//variables
private:
	std::string m_StrFunction;
	double m_LinearExtremeHigh;
	double m_LinearExtremeLow;

//functions
public:
	CauchyFunction(std::string func, double high, double low);
	virtual ~CauchyFunction();
	double m_IntegtrateFunc(unsigned int no);
	void m_Metropolis(std::string filename, unsigned int interator);

private:
	double m_Function(double x);
};

