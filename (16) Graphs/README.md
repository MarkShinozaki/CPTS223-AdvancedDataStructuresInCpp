# Graphs

## Introduction
A graph \(G = (V, E)\) consists of a set of vertices \(V\) and a set of edges \(E\). Graphs are used to model pairwise relations between objects.

## Types of Graphs
### Directed Graphs
- Edges have a direction (e.g., \( (v, w) \)).
### Undirected Graphs
- Edges do not have a direction (e.g., \( (v, w) \) is the same as \( (w, v) \)).
### Weighted Graphs
- Edges have weights or costs associated with them.
### Unweighted Graphs
- Edges do not have weights.
### Simple Graphs
- No loops or multiple edges.
### Multigraphs
- Multiple edges between the same set of vertices.
### Complete Graphs
- Every pair of vertices is connected by an edge.
### Bipartite Graphs
- Vertices can be divided into two disjoint sets such that every edge connects a vertex in one set to a vertex in the other set.
### Trees
- A connected acyclic undirected graph.
### DAGs (Directed Acyclic Graphs)
- Directed graphs with no cycles.

## Graph Terminology
- **Vertex Degree**: Number of edges incident to a vertex.
- **Path**: Sequence of vertices where each adjacent pair is connected by an edge.
- **Cycle**: A path that starts and ends at the same vertex with all other vertices distinct.
- **Connected Graph**: There is a path between any two vertices.
- **Strongly Connected Graph**: Directed graph where there is a directed path between any two vertices.
- **Weakly Connected Graph**: If the graph is undirected, it is connected if replacing all of its directed edges with undirected edges forms a connected graph.

## Graph Representation
### Adjacency Matrix
- A 2D array where each element indicates if there is an edge between a pair of vertices.
### Adjacency List
- An array of lists where each list represents a vertex and contains all adjacent vertices.

## Graph Traversal
### Breadth-First Search (BFS)
- Explores all neighbors at the present depth before moving on to nodes at the next depth level.
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
### Depth-First Search (DFS)
- Explores as far as possible along each branch before backtracking.
```cpp
void DFS(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(u, adj, visited);
        }
    }
}
```










---

### [Next Section: (17) NP-Completeness](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(17)%20NP-Completeness)
