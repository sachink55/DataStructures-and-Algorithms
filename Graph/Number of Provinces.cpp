//leetcode-547 : Number of Provinces
//Approach - DFS

class Solution {
public:
    void dfs(int src,unordered_map<int, bool>&vis, int n, vector<vector<int>>& isConnected){
        //mark src as visited
        vis[src] = true;

        //node ke nbr, node wale row ke har col me milnge
        int row = src;

        for(int col = 0; col<n; col++){
            int nbr = col;
            if(isConnected[row][nbr] == 1){
                if(!vis[nbr]){
                    dfs(nbr, vis, n, isConnected);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, bool>vis;
        int provinces = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, n, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};