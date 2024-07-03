# Advanced Data Structures, NP-Completeness, and Conclusions

## Course Overview
- Focuses on advanced data structures such as trees, hash tables, heaps, disjoint sets, and graphs.
- Emphasis on algorithm development and analysis, including operations like insert, delete, search, and sort.
- Applications are implemented using object-oriented design in C++.

## Analysis Tools
- Counting primitive operations.
- Exponents, logarithms, and summations.
- Analyzing recursive solutions with recurrence equations, e.g., \( T(N) = 2T(N/2) + \Theta(N) \).
- Proof techniques: induction and contradiction.
- Rate of growth notation: \( O \), \( \Omega \), \( \Theta \).

## Object-Oriented Design in C++
- Encapsulation: Class = Data + Methods.
- Information hiding and operator overloading.
- Use of templates and the Standard Template Library (STL).

## Basic Data Structures
- Lists, stacks, and queues.
- \( O(1) \) insert/delete, \( O(N) \) search.
- STL: `vector`, `list`, `stack`, `queue`.

## Advanced Data Structures
### Trees
- Binary search tree: \( O(\log N) \) insert, delete, search.
- Balanced BST: AVL and Splay trees.
- Massive trees: B-tree.
- STL: `set`, `map`.

### Hash Tables
- \( O(1) \) insert and search.
- Collision resolution: chaining, open addressing.
- Good hash functions, probe sequences, rehashing, extendible hashing.
- STL: `unordered_set`, `unordered_map`.

### Heaps (Priority Queues)
- Partially ordered elements.
- Heap: complete binary tree.
- \( O(\log N) \) insert, delete (worst-case), \( O(1) \) insert (average-case).
- Mergeable heaps: Binomial heap.
- STL: `priority_queue`.

### Disjoint Sets
- Implement equivalence class operations: Find and Union.
- Tree representation, union by rank, path compression.
- \( O(1) \) find, union (average-case).

### Graphs
- Representations: adjacency list vs. adjacency matrix.
- Algorithms:
  - BFS: \( O(V+E) \)
  - DFS: \( O(V+E) \)
  - Topological sort (DFS): \( O(V+E) \)
  - Shortest path: \( O(E \log V) \)
  - Maximum flow: \( O(E^2 \log V) \)
  - Minimum spanning tree: \( O(E \log V) \)
  - Biconnectivity and articulation points (DFS): \( O(V+E) \)
  - Euler circuits (DFS): \( O(V+E) \)
  - Strongly-connected components (DFS): \( O(V+E) \)

## Algorithm Design and Analysis: Sorting
### Comparison Sorts
- Insertion sort.
- Merge sort.
- Heap sort.
- Quicksort.
- Lower bound: \( \Theta(N \log N) \).

### Linear Sorting
- Counting sort.
- Bucket sort.
- External sorting.

## Hard Problems and NP-Completeness
- Exponential growth rates for hard problems: \( n^2 \), \( n^3 \), \( 2^n \), \( 3^n \).
- Classes of hard problems: NP-Hard, NP, P, NP-Complete.
- Approximation algorithms and their use.

## Applications
- Operating systems, compilers, databases, route planning, dictionary/symbol lookup, molecular analysis, image processing, theory of computation, and more.

## Problem-Solving
- Design appropriate data structures and algorithms.
- Evaluate and analyze performance to show improvements.




---

### [First Section: (1) Algorithm Analysis](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(1)%20Algorithm%20Analysis)
