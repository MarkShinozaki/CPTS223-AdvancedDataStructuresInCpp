#include "Sort.h"

using namespace std;

int main() {
  vector<int> a{5,3,5,6,2,9,5,1,4,1,3};
  vector<int> b = a;
  quicksort(a);
  a = b;
  insertionSort(a);
  a = b;
  mergeSort(a);
  return 0;
}
