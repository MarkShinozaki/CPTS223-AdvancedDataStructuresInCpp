// MaxSubSum.h
//
// HW4 Solution
// CPTS 223 - Spring 2022

#ifndef MAXSUBSUM_H
#define MAXSUBSUM_H

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator mss_iter;

class MaxSubSum {
public:
	MaxSubSum();
	void Insert(int index, int val);
	int Sum() const;
	friend ostream & operator<<(ostream & os, const MaxSubSum & mss);

private:
	void Update();
	int sequenceStart, sequenceEnd;
	vector<int> sequence;
};

#endif
