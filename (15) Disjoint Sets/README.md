# Disjoint Sets and Union-Find Data Structures

## Introduction
- Disjoint sets are used to manipulate equivalence relations.
- Operations: `Find(x)` to find the set containing `x`, and `Union(x, y)` to merge the sets containing `x` and `y`.

## Equivalence Relations
- **Reflexive**: \(a R a\) for all \(a \in S\).
- **Symmetric**: \(a R b\) iff \(b R a\).
- **Transitive**: \(a R b\) and \(b R c\) implies \(a R c\).

## Equivalence Classes
- Subsets \( S_i \) of \( S \) such that:
  - For all \( a, b \in S_i \), \( (a R b) \).
  - For all \( a \in S_i, b \in S_j, i \neq j \), \( \neg(a R b) \).

## Operations
### Find(a)
- Returns a representative of the set containing `a`.
```cpp
int find(int a) {
    if (s[a] < 0) return a;
    else return find(s[a]);
}
```
### Union(S_i, S_j)
- Merges the sets `S_i` and `S_j`.
```cpp
void union(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        s[rootA] = rootB;
    }
}
```
## Implementation Approaches
### Array-Based
- Maintain an array where each element points to the representative.
- **Find**: $𝑂(1)$ 
- **Union**: $𝑂(𝑁)$

### Linked List-Based
- Each set is a linked list; union involves concatenating lists.
- **Union**: **$𝑂$(size of larger list)**

### Tree-Based
- Represent each set as a tree.
- **Find**: Returns the root element of the tree containing `a`.
- **Union**: Links the root of one tree to another.

```cpp
int find(int x) {
    if (s[x] < 0)
        return x;
    else
        return s[x] = find(s[x]);
}

void union(int root1, int root2) {
    if (root1 != root2) {
        s[root2] = root1;
    }
}
```
### Optimized Techniques
#### Union by Size
- Attach the smaller tree to the larger tree.
```cpp
void unionBySize(int root1, int root2) {
    if (root1 != root2) {
        if (s[root2] < s[root1])
            s[root1] = root2;
        else {
            if (s[root1] == s[root2])
                s[root1]--;
            s[root2] = root1;
        }
    }
}
```
### Union by Height (Rank)
- Attach the shorter tree to the taller tree.

```cpp
void unionByHeight(int root1, int root2) {
    if (root1 != root2) {
        if (s[root2] < s[root1])
            s[root1] = root2;
        else {
            if (s[root1] == s[root2])
                s[root1]--;
            s[root2] = root1;
        }
    }
}
```
### Path Compression
- During `Find`, make all nodes on the path point directly to the root.

```cpp
int findWithPathCompression(int x) {
    if (s[x] < 0)
        return x;
    else
        return s[x] = find(s[x]);
}
```

### Performance
- Without optimization, Find can take $𝑂(𝑁)$ in the worst case.
- With Union by Size or Height and Path Compression, the amortized time is $𝑂(log∗ 𝑁)$

### Applications
- Maze generation.
- Finding connected components of a graph.
- Computing shorelines of a terrain.
- Molecular identification from fragmentation.
- Image processing.

### Example: Maze Generation
- Start with walls everywhere.
- Randomly choose a wall that separates two disconnected cells.
- Continue until start and finish cells are connected.

```cpp
Copy code
void generateMaze(int mazeSize) {
    // Maze generation logic using union-find
}
```

### Summary
- Disjoint sets data structure provides a simple, fast solution to equivalence problems.
- Array-based implementation offers average-case $𝑂(1)$ time per operation.
- Numerous applications in computer science and related fields.

---

### [Next Section: (16) Graphs](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(16)%20Graphs)
