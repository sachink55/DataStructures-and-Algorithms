//leetcode-802 : Find Eventual Safe States - https://leetcode.com/problems/find-eventual-safe-states/ 

//Approach : if a node is part of the cycle or it is reachable from the cycle then it is not safe. So, we will find the nodes which are not part of the cycle and are not reachable from the cycle. These nodes are safe.

//Time Complexity : O(V+E)
//Space Complexity : O(V)

class Solution {
public:
    // function to check cycle in directed graph using dfs
    bool checkCycleDfs(vector<vector<int>>& graph, int src, unordered_map<int, bool>& vis,
        unordered_map<int, bool>& dfsVis) {
        vis[src] = true;
        dfsVis[src] = true;

        for (auto nbr : graph[src]) {
            if (!vis[nbr]) {
                bool isCyclic = checkCycleDfs(graph, nbr, vis, dfsVis);
                if (isCyclic)
                    return true;
            } else if (vis[nbr] && dfsVis[nbr]) {
                // milgya cycle
                return true;
            }
        }
        dfsVis[src] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> vis, dfsVis;
        int V = graph.size();
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                checkCycleDfs(graph, i, vis, dfsVis);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; ++i) {
            if (!dfsVis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//Approach-2 : Using Topological Sort

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < V; i++) {
            for (auto nbr : graph[i]) {
                adj[nbr].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};