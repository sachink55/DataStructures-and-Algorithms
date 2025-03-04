//gfg - Undirected Graph Cycle

//Approach: Using DFS

class Solution {
  public:
    bool checkCycle(int src, unordered_map<int,bool>& vis, int parent, vector<vector<int>>& adj) {
        vis[src] = true;
        
        for(auto nbr: adj[src]) {
            if(nbr == parent) {
                continue;
            }
            if(!vis[nbr]) {
                bool ans = checkCycle(nbr, vis, src, adj);
                if(ans == true) {
                    return true;
                }
            }
            else if(vis[nbr]==1 ) {
                return true;
            }
        }
        return false;
    }
    

    bool isCycle(vector<vector<int>>& adj) {
        unordered_map<int,bool> vis;
        int V = adj.size();
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                int parent = -1;
                bool isCyclic = checkCycle(i, vis, parent, adj);
                if(isCyclic == true) {
                    return true;
                }
            }
        }
        return false;
    }
};


//Approach-2: Using BFS

class Solution {
  public:
      bool solve(int src,unordered_map<int,bool>& visited,vector<vector<int>>& adj) {
          queue<int> q;
          unordered_map<int,int> parent;
          //intiial state
          q.push(src);
          visited[src] = true;
          parent[src] = -1; 
    
          while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr : adj[frontNode]){
                if(nbr == parent[frontNode]) {
                    continue;
                }
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
                else if(visited[nbr] = true){
                    //cycle found
                    return true;
                }
            }
          }
        return false;
    } 
    
    bool isCycle(vector<vector<int>>& adj) {
      int V = adj.size();
      unordered_map<int,bool> visited;
      for(int i=0; i<V; i++) {
            if(!visited[i]) {
                bool ans = solve(i, visited,adj);
                if(ans == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

