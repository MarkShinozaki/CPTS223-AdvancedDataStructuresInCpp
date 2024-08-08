// MaxSubSum.cc
//
// Homework 4 Solution
// CPTS 223 - Spring 2022

#include <ostream>
#include "MaxSubSum.h"

using namespace std;

MaxSubSum::MaxSubSum() {
	sequenceStart = 0;
	sequenceEnd = -1;
}

void MaxSubSum::Insert(int index, int val) {
	// Insert val at given index in list, shifting values at index to the right.
	// If index is beyond the number of stored elements, then add val to the end.
	mss_iter itr = sequence.begin();
	if (index < sequence.size()) {
		advance(itr, index);
	} else {
		index = sequence.size();
		itr = sequence.end();
	}
	sequence.insert(itr, val);
	if (sequence.size() == 1) {
		// Only one element in sequence
		//cout << "Case 0: ";
		sequenceStart = sequenceEnd = 0;
	} else if (Sum() < 0) { // extra credit special case: vector contains only negative numbers
		Update();
	} else if (index < sequenceStart) {
		//cout << "Case 1: ";
		sequenceStart++;
		sequenceEnd++;
		if (val > 0) {
			Update();
		}
	} else if (index == sequenceStart) {
		//cout << "Case 2: ";
		sequenceEnd++;
		if (val < 0) {
			sequenceStart++;
		}
	} else if (index == sequenceEnd+1) {
		//cout << "Case 3: ";
		if (val >= 0) {
			sequenceEnd++;
		}
	} else if (index > sequenceEnd+1) {
		//cout << "Case 4: ";
		if (val > 0) {
			Update();
		}
	} else { // val being inserted in middle of current max sequence
		//cout << "Case 5: ";
		sequenceEnd++;
		if (val < 0) {
			Update();
		}
	}
}

int MaxSubSum::Sum() const {
	// Return sum of current maximum subsequence.
	int sum = 0;
	for (int i = sequenceStart; i <= sequenceEnd; i++) {
		sum += sequence[i];
	}
	return sum;
}

ostream & operator<<(ostream & os, const MaxSubSum & mss) {
	int sequenceStart = mss.sequenceStart;
	int sequenceEnd = mss.sequenceEnd;
	if (mss.sequence.size() == 0) {
		os << "[]";
	} else {
		os << "[" << mss.sequence[sequenceStart];
		for (int i = sequenceStart+1; i <= sequenceEnd; i++) {
			os << "," << mss.sequence[i];
		}
		os << "] = " << mss.Sum();
	}
	return os;
}

void MaxSubSum::Update() {
	// Special case where sequence is empty, i.e., no maximum subsequence sum
	if (sequence.empty()) {
		sequenceStart = 0;
		sequenceEnd = -1;
		return;
	}
	int maxSum = sequence[0];
	int thisSum = sequence[0];
	sequenceStart = sequenceEnd = 0;
	int i = 1;
	// Special case where sequence starts with negative numbers
	while ((i < sequence.size()) && (maxSum < 0)) {
		if (sequence[i] > maxSum) {
			maxSum = thisSum = sequence[i];
			sequenceStart = sequenceEnd = i;
		}
		i++;
	}
	// At this point, either we've reached the end of the sequence or we've
	// encountered the first positive number in the sequence (or both).
	int currentStart = sequenceStart;
	while (i < sequence.size()) {
		thisSum += sequence[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
			sequenceStart = currentStart;
			sequenceEnd = i;
		} else if (thisSum < 0) {
			thisSum = 0;
			currentStart = i+1;
		}
		i++;
	}
}

