//Bellman's Ford Algorithm for Shortest Path in a Graph (Negative Edges)
//TC : O(V*E)
//SC : O(V)

//Approach: Relax all edges V-1 times to find the shortest paths from the source.
//Check for negative cycles by relaxing edges once more; if any distance improves, a negative cycle exists.

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool directed) {
        adjList[u].push_back({v, wt});
        if (!directed) {
            adjList[v].push_back({u, wt});
        }
    }

    // Print adjacency list
    void printAdjList() {
        for (auto& node : adjList) {
            cout << node.first << " -> ";
            for (auto& nbr : node.second) {
                cout << "{" << nbr.first << ", " << nbr.second << "}, ";
            }
            cout << endl;
        }
    }

    // Bellman-Ford Algorithm implementation
    void bellmanFord(int V, int src) {
        vector<int> dist(V, INT_MAX); // Distance array
        dist[src] = 0;

        // Relax all edges (n-1) times
        for (int i = 0; i < V - 1; ++i) {
            for (auto& [u, nbr] : adjList) {
                for (auto& [v, wt] : nbr) {
                    if (dist[u] != INT_MAX && dist[v] > dist[u] + wt) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Check for negative weight cycles
        bool hasNegativeCycle = false;
        for (auto& [u, nbr] : adjList) {
            for (auto& [v, wt] : nbr) {
                if (dist[u] != INT_MAX && dist[v] > dist[u] + wt) {
                    hasNegativeCycle = true;
                    break; 
                }
            }
            if (hasNegativeCycle) break; 
        }

        // Print results
        if (hasNegativeCycle) {
            cout << "Negative weight cycle detected!" << endl;
        } else {
            cout << "Shortest distances from node " << src << ":\n";
            for (int i = 0; i < V; ++i) {
                cout << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
            }
        }
    }
};

int main() {
    Graph g;

    g.addEdge(0, 1, -1, 1);  // A -> B
    g.addEdge(1, 4, 2, 1);   // B -> E
    g.addEdge(4, 3, -3, 1);  // E -> D
    g.addEdge(3, 2, 5, 1);   // D -> C
    g.addEdge(0, 2, 4, 1);   // A -> C
    g.addEdge(1, 2, 3, 1);   // B -> C
    g.addEdge(1, 3, 2, 1);   // B -> D
    g.addEdge(3, 1, 1, 1);   // D -> B

    cout << "Graph Structure:" << endl;
    g.printAdjList();
    cout << "\nBellman-Ford Results:" << endl;

    g.bellmanFord(5, 0); // 5 nodes, start from node 0

    return 0;
}