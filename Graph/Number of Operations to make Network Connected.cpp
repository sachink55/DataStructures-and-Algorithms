// leetcode-1319 : Number of Operations to Make Network Connected

//Approach : If there are n computers and n-1 connections are required to connect all the computers then we can say that all the computers can be connected. So, we will find the number of connected components in the graph and then we will find the number of redundant connections (extra edges). If the number of extra edges is greater than or equal to the number of connected components then we can connect all the computers. Otherwise, it is not possible to connect all the computers.

//Approach : Using Union Find (Disjoint Set)

class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

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

    int makeConnected(int n, vector<vector<int>>& connections) {
        //need to find nocc, no of Extra edges
        vector<int>parent(n);
        vector<int>rank(n, 0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        int noExtraEdges = 0;
        for(auto connection : connections){
            int u = connection[0];
            int v = connection[1];

            u = findParent(parent, u);
            v = findParent(parent, v);

            if(u!=v){
                unionSet(u, v, parent, rank);
            }
            else{
                ++noExtraEdges;
            }
        }
        int nocc = 0;
        for(int i=0; i<n; ++i){
            if(parent[i] == i){
                nocc++;
            }
        }
        int ans = nocc - 1;
        return noExtraEdges >= ans ? ans : -1;
    }
};

//******************************************************************************************/
//Approach-2 : Using DFS 

class Solution {
public:
    void dfs(int src, vector<int>& vis, vector<int> adj[]) {
        vis[src] = 1;
        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, vis, adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; 

        vector<int> adj[n];
        for (auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        int nocc = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                nocc++;
            }
        }

        return nocc - 1;
    }
};