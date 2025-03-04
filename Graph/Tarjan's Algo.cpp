//Tarjan's Algorithm to find Strongly Connected Components in a graph
//TC : O(V+E)
//SC : O(V)

//Approach: Perform DFS to get nodes in order of finishing times (topological sort). Use a stack to store nodes in order of finishing times. Traverse the graph using the ordering and count the number of strongly connected components.

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if (!direction) {  // undirected
            adjList[v].push_back(u);
        }
    }

    vector<vector<int>> findSSCs(int n) {
        int timer = 1;
        vector<vector<int>> ans;
        vector<int> tin(n, 0);    // Time of discovery
        vector<int> low(n, 0);    // Lowest discovery time
        unordered_map<int, bool> vis;

        // Start DFS from node 0 (assuming connected graph)
        tarzanDFS(0, -1, timer, tin, low, vis, ans);
        
        return ans;
    }

private:
    void tarzanDFS(int node, int parent, int &timer, vector<int>& tin, 
                vector<int>& low, unordered_map<int, bool>& vis, 
                vector<vector<int>>& ans) {
        
        vis[node] = true;
        tin[node] = low[node] = timer++;
        
        for (int nbr : adjList[node]) {
            if (nbr == parent) continue;
            
            if (!vis[nbr]) {
                tarzanDFS(nbr, node, timer, tin, low, vis, ans);
                low[node] = min(low[node], low[nbr]);
                
                // Check for bridge condition
                if (low[nbr] > tin[node]) {
                    ans.push_back({node, nbr});
                }
            }
            else {
                // Back edge - update low using neighbor's low
                low[node] = min(low[node], low[nbr]);
            }
        }
    }
};


int main() {
    Graph g;
    int n = 4;
    
    
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 0, 0);
    g.addEdge(1, 3, 0);
    
    vector<vector<int>> bridges = g.findSSCs(n);
    
    cout << "Critical Connections or SCCs :\n";
    for (auto bridge : bridges) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "]\n";
    }
    
    return 0;
}