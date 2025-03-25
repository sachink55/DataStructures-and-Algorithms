//Shortest Path using DFS in a Directed Acyclic Graph (DAG)

#include <bits/stdc++.h>
using namespace std;

// Directed and Weighted Graph
class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt}); // Directed edges only
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " : { ";
            for (auto j : i.second) {
                cout << "(" << j.first << " , " << j.second << "), ";
            }
            cout << "} " << endl;
        }
    }

    void topoOrderDfs(int node, stack<int>& topo, unordered_map<int, bool>& visited) {
        visited[node] = true;
        for (auto nbrPair : adj[node]) {
            int nbrNode = nbrPair.first;
            if (!visited[nbrNode]) {
                topoOrderDfs(nbrNode, topo, visited);
            }
        }
        topo.push(node);
    }

    void shortestPathDfs(int src, int n) {
        stack<int> topoOrder;
        unordered_map<int, bool> visited;

        // topological order for all nodes
        for (auto i : adj) {
            if (!visited[i.first]) {
                topoOrderDfs(i.first, topoOrder, visited);
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Process nodes in topological order
        while (!topoOrder.empty()) {
            int u = topoOrder.top();
            topoOrder.pop();
            for (auto nbrPair : adj[u]) {
                int v = nbrPair.first;
                int wt = nbrPair.second;
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Print distances
        cout << "Shortest distances from source " << src << ": " << endl;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 9);
    g.addEdge(0, 5, 14);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 11);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 9);

    g.printAdjList();

    int src = 0, n = 6; // 6 nodes (0 to 5)
    g.shortestPathDfs(src, n);

    return 0;
}
