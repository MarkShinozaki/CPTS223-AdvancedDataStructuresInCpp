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










---

### [Next Section: (18) Course Conclusion](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(18)%20Course%20Conclusion)
