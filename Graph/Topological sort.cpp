//Topological sort : A linear ordering of vertices such that for every directed edge u-v from vertex u to vertex v, u comes before v in the ordering.
// for DAG (Directed Acyclic Graph) only


#include <bits/stdc++.h>
using namespace std;

// Approach-1: Using BFS (Kahn's Algorithm)

vector<int> topoSortBFS(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);

    //initialise kardi indegree se
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            inDegree[v]++;
        }
    }

    //push all zero indegree wali node into queue
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topoOrder;
}

// Approach-2: Using DFS
void dfs(int src, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[src] = true;

    for (int nbr : adj[src]) {
        if (!visited[nbr]) {
            dfs(nbr, adj, visited, st);
        }
    }
    st.push(src);
}

vector<int> topoSortDFS(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topoOrder;
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }

    return topoOrder;
}

// TC: O(V + E) for both BFS and DFS 
// SC: O(V) for both BFS and DFS 

int main() {
    int V = 6;
    vector<int> adj[V];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topoOrderBFS = topoSortBFS(V, adj);
    cout << "Topological Sort (BFS): ";
    for (int v : topoOrderBFS) {
        cout << v << " ";
    }
    cout << endl;

    vector<int> topoOrderDFS = topoSortDFS(V, adj);
    cout << "Topological Sort (DFS): ";
    for (int v : topoOrderDFS) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}