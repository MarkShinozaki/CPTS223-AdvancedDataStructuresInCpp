# Sorting Algorithms
## 1. Comparison-Based Sorting

- **O(n²) Methods**: Insertion sort, Bubble sort.
- **Average Time O(n log n) Methods**: Quick sort.
- **O(n log n) Methods**: Merge sort, Heap sort.
- **Stable vs. Unstable Sorting**: Stability ensures equal elements retain their order.

## 2. Insertion Sort
- Best for small arrays or nearly sorted data.
- **Complexity**:
  - Worst-case: $𝑂(𝑛^2)$
  - Best-case: \$𝑂(𝑛)$
- **Algorithm**:
```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```
## 3. Merge Sort
- Divide and conquer approach.
- **Complexity**:
  - All cases: $𝑂(𝑛 log n)$
- **Algorithm**:
```cpp
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
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

## 4. Quick Sort
- Divide and conquer approach with partitioning.
- **Complexity**:
  - Worst-case: $𝑂(𝑛2)$
  - Average-case: $O(nlog n)$
- **Algorithm**:
```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```
## 5. Heap Sort 
- Based on binary heap data structure.
- **Complexity**:
  - All cases: $O(nlog n)$
- **Algorithm**:
```cpp
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
```
## 6. Non-Comparison-Based Sorting 
- **Counting Sort**: Efficient for integer sorting with limited range.
- **Radix Sort**: Sorts integers by processing individual digits.
- **Bucket Sort**: Distributes elements into buckets, sorts each bucket, and merges them.

## 7. Handling Duplicates in QuickSort 
- Adjust partitioning to handle duplicates effectively.
- Modified approach avoids worst-case $𝑂(𝑛^2)$ performance for identical elements.


## 8. Small Arrays in QuickSort
- Use InsertionSort for small sub-arrays to optimize performance



---

### [Next Section: (15) Disjoint Sets](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(15)%20Disjoint%20Sets)
