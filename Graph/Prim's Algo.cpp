//Prim's Algorithm to find Minimum Spanning Tree (MST) of a graph [undirected, weighted, connected graph]
// TC : O(ElogV)
// SC : O(V)


#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void prims(vector<vector<pair<int, int>>> &graph, int V) {
    // Priority queue to store the minimum weight edge at top
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Vector to store the minimum weight to reach each vertex
    vector<int> key(V, INT_MAX);
    
    // Vector to store the parent of each vertex in the MST
    vector<int> parent(V, -1);
    
    // Vector to keep track of vertices included in the MST
    vector<bool> inMST(V, false);
    
    key[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        // include vertex u in MST
        inMST[u] = true;
        
        // traverse all adjacent vertices of u
        for (auto &adj : graph[u]) {
            int v = adj.first;
            int wt = adj.second;
            
            // If v is not in MST and weight of (u, v) is smaller than current key of v
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
}

int main() {
    int V = 5; 
    vector<vector<pair<int, int>>> graph(V);
    
    // Add edges to the graph (u, v, weight)
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});
    
    prims(graph, V);
    
    return 0;
}

/*
Time Complexity: O(E log V), where E is the number of edges and V is the number of vertices.
Space Complexity: O(V), for storing the key, parent, and inMST arrays.
*/