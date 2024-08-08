// main.cc
//
// HW8 - CPTS 223 - Spring 2022

#include <chrono>
#include <random>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]) {
	int max_N;
	stringstream ss(argv[1]);
	ss >> max_N;
	for (int N = 1; N <= max_N; N++) {
		// Create sequence of random integers 1...N
		vector<int> random_sequence;
		random_sequence.clear();
		for (int i = 0; i < N; i++) random_sequence.push_back(i);
		random_shuffle(random_sequence.begin(), random_sequence.end());
		
		// Insert shuffled numbers into newly-created data structures
		vector<int>* v = new vector<int>;
		set<int>* s = new set<int>;
		unordered_set<int>* us = new unordered_set<int>;
		for (int i = 0; i < N; i++) {
			v->push_back(random_sequence[i]);
			s->insert(random_sequence[i]);
			us->insert(random_sequence[i]);
		}
		
		// Search for shuffled numbers and compute average run time
		// -- vector
		auto time_begin = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < N; i++) {
			find(v->begin(), v->end(), random_sequence[i]);
		}
		auto time_end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed_time = time_end - time_begin;
		double elapsed_time_v = elapsed_time.count() / ((double) N);
		
		// -- set
		time_begin = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < N; i++) {
			s->find(random_sequence[i]);
		}
		time_end = std::chrono::high_resolution_clock::now();
		elapsed_time = time_end - time_begin;
		double elapsed_time_s = elapsed_time.count() / ((double) N);
		
		// -- unordered_set
		time_begin = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < N; i++) {
			us->find(random_sequence[i]);
		}
		time_end = std::chrono::high_resolution_clock::now();
		elapsed_time = time_end - time_begin;
		double elapsed_time_us = elapsed_time.count() / ((double) N);

		cout << N << "," << elapsed_time_v << "," << elapsed_time_s << "," << elapsed_time_us << endl;
		
		delete v;
		delete s;
		delete us;
	}
	return 0;
}

/*
 * create vector, set, unordered_set
 * for N = 1 to max
 *   generate random sequence of the numbers 1 to N
 *   for each DS in (vector, set, unordered_set)
 *     insert numbers, one at a time, in order of the sequence into empty DS
 *   generate another random sequence of the numbers 1 to N
 *   for each data structure DS in (vector, set, unordered_set)
 *     search for numbers, one at a time, in order of the sequence
 *     compute the average time per search (i.e., total time / N)
 *   output n and average search times for vector, set, unordered_set (CSV format)
 *   
 *   Generate one plot showing the average search time vs. N for each DS (use different color for each)
 *   Comment on the difference between the three curves
 *   
 *   How to measure time?
 *   https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
 */