
# Algorithm Analysis Summary

## Common Topics

### Algorithm Definition and Purpose
- **Algorithm**: Well-defined computational procedures transforming inputs to outputs.
- **Purpose**:
  - Estimating time and memory for average and worst cases.
  - Identifying bottlenecks to optimize time.
  - Correct algorithm produces correct output for every input in finite time.

### Types of Analysis
- **Running time**: Measure of time taken by an algorithm to complete.
- **Memory usage**: Measure of memory utilized during execution.
- **Worst-case and Average-case Running Time**: 
  - **Worst-case**: The maximum time taken on any input of size \( N \).
  - **Average-case**: The expected time taken over all possible inputs of size \( N \).

### Rate of Growth and Asymptotic Notations
- **Big-O Notation (O)**: Upper bound of the time complexity.
  - Example: \( T(N) = O(f(N)) \) if there are constants \( c \) and \( n_0 \) such that \( T(N) \leq cf(N) \) when \( N \geq n_0 \).
- **Big-Omega Notation (Ω)**: Lower bound of the time complexity.
  - Example: \( T(N) = Ω(g(N)) \) if there are constants \( c \) and \( n_0 \) such that \( T(N) \geq cg(N) \) when \( N \geq n_0 \).
- **Theta Notation (Θ)**: Tight bound of the time complexity.
  - Example: \( T(N) = Θ(h(N)) \) if \( T(N) = O(h(N)) \) and \( T(N) = Ω(h(N)) \).
- **Little-oh Notation (o)**: Upper bound not tight.
  - Example: \( T(N) = o(p(N)) \) if for all constants \( c \), \( T(N) < cp(N) \) when \( N > n_0 \).

### Common Operations and Examples
- **O(1)**: Constant time operations.
  - Example: Accessing an array element.
  - Code: 
    ```cpp
    int x = arr[50];
    ```
- **O(N)**: Linear time operations.
  - Example: Summing elements of an array.
  - Code:
    ```cpp
    int sum(int arr[], int N) {
        int total = 0;
        for (int i = 0; i < N; ++i) {
            total += arr[i];
        }
        return total;
    }
    ```
- **O(N^2)**: Quadratic time operations.
  - Example: Bubble Sort.
  - Code:
    ```cpp
    void bubbleSort(int arr[], int N) {
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    ```
- **O(log N)**: Logarithmic time operations.
  - Example: Binary Search.
  - Code:
    ```cpp
    int binarySearch(int arr[], int left, int right, int x) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) return mid;
            if (arr[mid] < x) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    ```
- **O(N log N)**: Linearithmic time operations.
  - Example: Merge Sort.
  - Code:
    ```cpp
    void merge(int arr[], int l, int m, int r) {
        // Merge logic
    }
    
    void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
    ```

### Algorithm Examples and Analysis
- **Maximum Subsequence Sum Problem**
  - Multiple approaches with varying complexities (e.g., cubic, quadratic, linear).

- **Binary Search**
  - Logarithmic time complexity: \( O(\log N) \).
  
- **Brute Force Search**
  - Linear time complexity: \( O(N) \).

- **Bubble Sort**
  - Quadratic time complexity: \( O(N^2) \).

## Unique Topics in 4_algo_analysis.pdf

### Example Algorithms
- **Maximum Subsequence Sum Problem**
  - Detailed examples and step-by-step analysis of different approaches.

### Algorithm Specifics
- **Nested Loops Analysis**
  - Detailed breakdown of time complexities for various nested loop structures.
- **Reduction and Simplification**
  - Techniques to simplify and reduce Big-O expressions.

## Unique Topics in analysis (1).pdf

### Asymptotic Analysis Details
- **Estimation Methods**
  - Detailed explanation of asymptotic analysis as a method of grouping algorithms based on growth rate.
- **Benchmark Sensitivity**
  - Discussion on the sensitivity of benchmarks to input data variations.

### Big-O Analysis
- **Loop Analysis**
  - Detailed analysis of different types of loops (simple, nested, unrelated) and their time complexities.
- **Simplification Techniques**
  - Emphasis on dropping constants and lower-order terms in Big-O analysis.

---

### [Next Section: Abstract Data Types](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(2)%20Abstract%20Data%20Types)

