
# Heaps and Priority Queues

## Motivation and Applications
- Queues are standard for ordering tasks.
- Priority queues allow tasks with higher priority to be processed first.
- Applications include:
  - Operating system scheduling
  - Graph algorithms (e.g., shortest path)
  - Event simulation

## Priority Queue Specifications
- **Main operations**:
  - `insert` (enqueue): Adds an element based on priority.
  - `deleteMin` (dequeue): Removes and returns the element with the highest priority.
- **Performance Goals**:
  - Fast operations with `O(log N)` time complexity for `insert` and `deleteMin`.

## Binary Heap
### Structure Property
- A complete binary tree where each level is fully filled except possibly the last level, which is filled from left to right.
### Heap-Order Property
- For a min-heap, the key of each node is less than or equal to the keys of its children, ensuring the minimum key is always at the root.

### Array Representation
Given an element at index `i`:
- Left child: `2i`
- Right child: `2i + 1`
- Parent: `floor(i/2)`

## Heap Operations
### Insert
- Insert the new element at the next available position and percolate up to maintain the heap-order property.
```cpp
void insert(int x) {
    heap[++size] = x;
    int i = size;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}
```

### deleteMin
- Remove the root element, replace it with the last element, and percolate down to restore the heap-order property.
```cpp
int deleteMin() {
    int min = heap[1];
    heap[1] = heap[size--];
    int i = 1;
    while (2 * i <= size) {
        int child = 2 * i;
        if (child != size && heap[child + 1] < heap[child]) child++;
        if (heap[i] > heap[child]) {
            swap(heap[i], heap[child]);
            i = child;
        } else break;
    }
    return min;
}
```
### Other Heap Operations
- **decreaseKey**: Lowers the value of an element and percolates up.
- **increaseKey**: Increases the value of an element and percolates down.
- **remove**: Decreases the key to negative infinity and deletes the minimum element.

### Building a Heap
- Construct a heap from an initial set of `N` items.
- Methods include:
  - Performing `N` inserts.
  - Assuming the set is a heap and performing percolate-down from each internal node.







---

### [Next Section: (14) Sorting Algorithms](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(14)%20Sorting%20Algorithms)
