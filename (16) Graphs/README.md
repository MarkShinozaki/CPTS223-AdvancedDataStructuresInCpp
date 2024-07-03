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
### Graph Algorithms
#### Topological Sort
- Ordering of vertices in a DAG such that for every directed edge 𝑢𝑣, vertex 𝑢 comes before 𝑣.

```cpp
void topologicalSortUtil(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            topologicalSortUtil(u, adj, visited, Stack);
        }
    }
    Stack.push(v);
}

void topologicalSort(vector<vector<int>>& adj) {
    stack<int> Stack;
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
```

### Shortest Path Algorithms
#### Dijkstra’s Algorithm
- Finds the shortest paths from a source vertex to all vertices in a weighted graph with non-negative weights.
```cpp
void dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(adj.size(), INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < adj.size(); ++i)
        cout << i << " " << dist[i] << endl;
}
```
### Bellman-Ford Algorithm
- Finds the shortest paths from a source vertex to all vertices in a weighted graph with negative weights.

```cpp
void bellmanFord(vector<vector<int>>& edges, int V, int E, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            cout << "Graph contains negative weight cycle" << endl;
    }
    for (int i = 0; i < V; ++i)
        cout << i << " " << dist[i] << endl;
}
```

### Floyd-Warshall Algorithm
- Finds shortest paths between all pairs of vertices.

```cpp
void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
```

### Minimum Spanning Tree (MST) Algorithms
#### Kruskal’s Algorithm
- Finds the MST by sorting the edges by weight and adding them one by one while avoiding cycles.

```cpp
struct Edge {
    int src, dest, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    vector<Edge> result;
    for (auto edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);
        if (x != y) {
            result.push_back(edge);
            unionSet(parent, rank, x, y);
        }
    }
    for (auto edge : result)
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
}
```
### Prim’s Algorithm
- Finds the MST by starting from a vertex and growing the MST one vertex at a time.

```cpp
void primMST(vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int V = adj.size();
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push({0, 0});
    key[0] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \n";
}
```
### Strongly Connected Components (SCC)
- Subgraphs where every vertex is reachable from every other vertex in the subgraph.

```cpp
void SCCUtil(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack) {
    visited[u] = true;
    for (int i : adj[u]) {
        if (!visited[i])
            SCCUtil(i, adj, visited, Stack);
    }
    Stack.push(u);
}

void SCC(vector<vector<int>>& adj) {
    stack<int> Stack;
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i])
            SCCUtil(i, adj, visited, Stack);
    }
    vector<vector<int>> transpose(adj.size());
    for (int v = 0; v < adj.size(); v++) {
        for (int i : adj[v])
            transpose[i].push_back(v);
    }
    fill(visited.begin(), visited.end(), false);
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();
        if (!visited[v]) {
            stack<int> component;
            SCCUtil(v, transpose, visited, component);
            while (!component.empty()) {
                cout << component.top() << " ";
                component.pop();
            }
            cout << endl;
        }
    }
}
```
### Bipartite Checking
- Determines if a graph is bipartite using BFS or DFS.
```cpp
bool isBipartite(vector<vector<int>>& adj, int src) {
    vector<int> colorArr(adj.size(), -1);
    colorArr[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            } else if (colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}
```

### Example Applications
#### Airport Connections
- Model airports as vertices and flights as edges.

#### Road Trip Route Planning
- Model cities as vertices and roads as edges.

#### Traffic Flow
- Model intersections as vertices and roads as edges with weights representing travel times.

#### Networking
- Model computers as vertices and connections as edges.

#### LinkedIn
- Model users as vertices and connections as edges.

#### Course Prerequisites (DAG)
- Model courses as vertices and prerequisites as directed edges.



### Example: Dijkstra’s Algorithm


```cpp
void dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(adj.size(), INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < adj.size(); ++i)
        cout << i << " " << dist[i] << endl;
}
```

















---

### [Next Section: (17) NP-Completeness](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(17)%20NP-Completeness)
