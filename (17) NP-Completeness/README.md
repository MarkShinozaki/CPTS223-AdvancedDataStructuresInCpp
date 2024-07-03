# NP-Completeness and Graphs

## NP-Completeness

### Hard Graph Problems
- **Easy Problems**:
  - Euler circuit: Find a path that traverses each edge once.
  - Single-source, unweighted shortest path.
- **Hard Problems**:
  - Hamiltonian cycle: Find a simple path that visits each vertex once.
  - Longest simple path problem.
  - Traveling Salesman Problem (TSP): Find the shortest path that visits each vertex once in a weighted graph.

### Running Times for Hard Problems
- Exponential running times grow extremely quickly.
- Example growth rates: \( n^2 \), \( n^3 \), \( 2^n \), \( 3^n \).

### Classes of Hard Problems
- **NP (Non-deterministic Polynomial time)**: Problems that can be verified in polynomial time.
- **NP-Complete**: Hardest problems in NP.
- **NP-Hard**: Problems at least as hard as NP-Complete problems but not necessarily in NP.

### Undecidable Problems
- Problems that cannot be solved with any algorithm (e.g., the halting problem).

### NP Problems
- Decision problems turned into yes/no questions (e.g., Is there a TSP tour with cost ≤ K?).
- A problem is in NP if a solution can be verified in polynomial time.

### NP-Complete Problems
- Examples: SAT, Clique, Vertex Cover, Hamiltonian Cycle, TSP.
- SAT was the first problem proven to be NP-Complete by Stephen Cook in 1971.
- Reduction: A known NP-Complete problem can be reduced to another problem to prove it is NP-Complete.

## Graphs

### Introduction
A graph \(G = (V, E)\) consists of vertices \(V\) and edges \(E\). Graphs model pairwise relations.

### Types of Graphs
- **Directed Graphs**: Edges have a direction.
- **Undirected Graphs**: Edges do not have a direction.
- **Weighted Graphs**: Edges have weights.
- **Unweighted Graphs**: Edges do not have weights.
- **Simple Graphs**: No loops or multiple edges.
- **Multigraphs**: Multiple edges between the same set of vertices.
- **Complete Graphs**: Every pair of vertices is connected.
- **Bipartite Graphs**: Vertices divided into two disjoint sets.
- **Trees**: Connected acyclic undirected graph.
- **DAGs**: Directed Acyclic Graphs with no cycles.

### Graph Terminology
- **Vertex Degree**: Number of edges incident to a vertex.
- **Path**: Sequence of vertices connected by edges.
- **Cycle**: Path starting and ending at the same vertex.
- **Connected Graph**: Path between any two vertices.
- **Strongly Connected Graph**: Directed path between any two vertices.
- **Weakly Connected Graph**: Connected when directed edges are replaced with undirected edges.

### Graph Representation
- **Adjacency Matrix**: 2D array indicating edges between vertex pairs.
- **Adjacency List**: Array of lists representing vertices and adjacent vertices.

### Graph Traversal
#### Breadth-First Search (BFS)
```cpp
void BFS(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}
```

Examples of NP-Complete Problems That Aren't Graph Algorithms
1. Boolean Satisfiability Problem (SAT)
  - Given a Boolean formula, determine if there is an assignment of truth values to variables that makes the formula true.
  - Example: (𝑥 ∨ ¬ 𝑦 ) ∧ (𝑦 ∨ 𝑧)

Knapsack Problem

Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
Example: Maximize value subject to weight constraints.
Subset Sum Problem

Given a set of integers, is there a non-empty subset whose sum is zero?
Example: Given {3, -1, 7, 5}, find if any subset sums to zero.
Partition Problem

Determine if a given set of positive integers can be partitioned into two subsets with equal sums.
Example: Given {1, 5, 11, 5}, determine if it can be split into two subsets with equal sums.
3-SAT Problem

A specific case of SAT where each clause in the formula has exactly three literals.
Example: 
(
𝑥
1
∨
¬
𝑥
2
∨
𝑥
3
)
∧
(
¬
𝑥
1
∨
𝑥
4
∨
¬
𝑥
3
)
(x 
1
​
 ∨¬x 
2
​
 ∨x 
3
​
 )∧(¬x 
1
​
 ∨x 
4
​
 ∨¬x 
3
​
 ).
Job Scheduling Problem

Given a set of jobs, each with a start time, end time, and profit, find the maximum profit subset of non-overlapping jobs.
Example: Maximize profit by scheduling non-overlapping jobs.
Bin Packing Problem

Pack objects of different volumes into a finite number of bins or containers each of a fixed given volume in a way that minimizes the number of bins used.
Example: Minimizing bins used for packing different-sized items.










---

### [Next Section: (18) Course Conclusion](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(18)%20Course%20Conclusion)
