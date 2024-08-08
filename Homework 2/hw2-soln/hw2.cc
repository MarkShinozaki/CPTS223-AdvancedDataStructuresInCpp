// CptS 223 Homework 2
//
// Author: Larry Holder
//
// Implements two versions of the IndexEqual procedure that returns true
// if some element of the given array A is equal to its index, i.e.,
// A[k] = k. One version is recursive, and the other is iterative.
//
// The procedures are tested by executing them on several sample arrays
// and recording the number of comparisons between A[k] and k made by
// each procedure.

#include <iostream>
#include <vector>

#define NUM_TRIALS 100

using namespace std;

int comparisonCounter; // global

bool IndexEqualRec (vector<int> & A, int i, int j)
{
  if (i > j)
    return false;
  else {
    int k = (i + j) / 2; // implied floor
    comparisonCounter++;
    if (A[k] == k)
      return true;
    else {
      comparisonCounter++;
      if (A[k] < k)
        return IndexEqualRec (A, k+1, j);
      else return IndexEqualRec (A, i, k-1);
    }
  }
}

bool IndexEqualIter (vector<int> & A, int i, int j)
{
  for (int k = 0; k < A.size(); k++)
  {
    comparisonCounter++;
    if (A[k] == k)
      return true;
  }
  return false;
}

int main ()
{
  int i, k;
  int recCount = 0, recTotal = 0;
  int iterCount = 0, iterTotal = 0;
  vector<int> A (NUM_TRIALS);

  cout << " k  \tRecursive \tIterative\n";
  cout << "----- \t--------- \t---------\n";
  for (k = 0; k < NUM_TRIALS; k++)
  {
    // populate ordered array so that only A[k] = k
    A[k] = k;
    for (i = 0; i < k; i++)
      A[i] = i - 1;
    for (i = k+1; i < NUM_TRIALS; i++)
      A[i] = i + 1;

    // call recursive IndexEqual on A
    comparisonCounter = 0;
    IndexEqualRec (A, 0, NUM_TRIALS - 1);
    recCount = comparisonCounter;
    recTotal += recCount;
 
    // call iterative IndexEqual on A
    comparisonCounter = 0;
    IndexEqualIter (A, 0, NUM_TRIALS - 1);
    iterCount = comparisonCounter;
    iterTotal += iterCount;

    // output result for kth array
    cout << k << "\t" << recCount << "\t\t" << iterCount << endl;
  }
  // output totals
  cout << "----- \t--------- \t---------\n";
  cout << "Total\t" << recTotal << "\t\t" << iterTotal << endl;

  return 0;
}
