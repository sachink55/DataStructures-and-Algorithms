//Dijkstra's Algorithm to find the shortest path from a source node to all other nodes in a weighted graph


#include<bits/stdc++.h>
using namespace std;

// using a priority queue (min-heap)
// TC: O((V + E) log V)
// SC: O(V + E)
void dijkstra_pq(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
    // Min-heap priority queue to store (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        // Skip if a shorter path to u has already been found
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

// Using Set
// TC: O((V + E) log V)
// SC: O(V + E)
void dijkstra_set(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
    // Set to store (distance, node), ordered by distance
    set<pair<int, int>> s;
    dist[start] = 0;
    s.insert({0, start});
    
    while (!s.empty()) {
        auto it = s.begin();
        int d = it->first;
        int u = it->second;
        s.erase(it); // Remove the current node from the set
        
        // Skip if a shorter path to u has already been found
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                // Update distance and add to the set
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }
}

int main() {
    int n = 4; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);
    
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 6});
    adj[2].push_back({3, 3});
    
    vector<int> dist_pq(n, INT_MAX);
    dijkstra_pq(0, adj, dist_pq);
    cout << "Using priority queue:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << (dist_pq[i] == INT_MAX ? -1 : dist_pq[i]) << "\n";
    }
    
    vector<int> dist_set(n, INT_MAX);
    dijkstra_set(0, adj, dist_set);
    cout << "\nUsing set:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << (dist_set[i] == INT_MAX ? -1 : dist_set[i]) << "\n";
    }
    
    return 0;
}
