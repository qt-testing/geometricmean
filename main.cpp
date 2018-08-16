#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

bool generateInputData(const string filepath, int valuesCount);

int main(int argc, char **argv)
{
	const string inputFilepath = "/home/alexander/programming/github/fstream/input.txt";
	const string outputFilepath = "/home/alexander/programming/github/fstream/output.txt";

	if (!generateInputData(inputFilepath, 10000)) {
		return 1;
	}

	return 0;
}

bool generateInputData(const string filepath, int valuesCount)
{
	ofstream out(filepath);
	if (!out.is_open()) {
		cerr << "Output file is not opened !" << endl;
		return false;
	}

	out << valuesCount << endl;

	random_device rd;
	default_random_engine e1(rd());
	uniform_real_distribution<> distribution(-10000.0, 10000.0);

	for (int i = 0; i < valuesCount; ++i) {
		out << distribution(e1) << endl;
	}

	out.close();

	return true;
}
