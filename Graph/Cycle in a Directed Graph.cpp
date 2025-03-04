//gfg - Cycle in Directed Graph

//Approach: Using DFS 

class Solution {
  public:
    bool checkCyclic(int src, unordered_map<int,bool>& vis,
        unordered_map<int,bool> &dfsTrack,vector<vector<int>> &adj ) {
            
        vis[src] = true;
        dfsTrack[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!vis[nbr]) {
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                if(ans == true) {
                    return true;
                }
            }
            if(vis[nbr]==1 && dfsTrack[nbr]==1) {
                //cycle present
                return true;
            }
        }
        
        //backtrack - [yahi galti karta hu]
        dfsTrack[src] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> adj) {
        unordered_map<int, bool>vis;
        unordered_map<int, bool>dfsTrack;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                bool ans = checkCyclic(i, vis, dfsTrack, adj);
                if(ans) return true;
            }
        }
        return false;
    }
};
