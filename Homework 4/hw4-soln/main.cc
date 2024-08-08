// main.cc
//
// HW4 - CPTS 223 - Spring 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MaxSubSum.h"

using namespace std;

int main(int argc, char* argv[]) {
	MaxSubSum mss;
	ifstream infile(argv[1]);
	string line;
	while (getline(infile, line)) {
		int index, val;
		stringstream ss(line);
		ss >> index >> val;
		mss.Insert(index, val);
		cout << mss << endl;
	}
	infile.close();
	return 0;
}
