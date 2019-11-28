#include<map>
#include<fstream>
#include "cauchy_test.h"

void CreateHistogramFile(std::string a, double low, double high) {

	std::map<int, int> histogram;

	double steps = (high - low) / 100.;

	std::ifstream f(a.c_str());

	while (!f.eof()) {

		double point = low;
		double value;
		f >> value;
		//std::cout<<"value "<<value<<std::endl;

		for (int i = 0; i < 100; i++) {

			point += steps;

			if (value < point) {


				//std::cout<<"point "<<point<<std::endl;
				histogram[i]++;
				break;
			}

		}
	}
	f.close();

	std::ofstream of("input_plotting.csv");

	double ranges = low + steps / 2.;
	for (int i = 0; i < 100; i++) {
		ranges += steps;
		of << ranges << " " << histogram[i] << std::endl;
	}



}