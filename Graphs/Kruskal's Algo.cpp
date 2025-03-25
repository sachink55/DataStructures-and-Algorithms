//Kruskal's Algorithm : to find the minimum spanning tree (MST) in a graph [undirected, weighted, connected graph]

// TC: O(ElogE + ElogV) = O(ElogE) 
// SC: O(V+E)

class Solution {
public:
    static bool mycmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];  // sorting edges based on weight
    }

    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }
    //Union function using Rank
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } else if (rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // make each node its own parent [disjoint set]
        for (int u = 0; u < V; ++u) {
            parent[u] = u;
        }

        // convert adjacency list to edge list (u, v, w)
        vector<vector<int>> edges;
        for (int u = 0; u < V; ++u) {
            for (auto edge : adj[u]) {
                int v = edge[0];
                int w = edge[1];
                edges.push_back({u, v, w});
            }
        }

        // sort edges by weight 
        sort(edges.begin(), edges.end(), mycmp);

        int ans=0;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //
            if (findParent(parent, u) != findParent(parent, v)) { 
                unionSet(u, v, parent, rank);
                ans += w;
            }
        }

        return ans;
    }
};
