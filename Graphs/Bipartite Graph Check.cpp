//leetcode - 785 : Is Graph Bipartite?

//Approach : BFS 
class Solution {
private:
    bool checkBipartite(int src, int V, vector<vector<int>>& graph, vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr : graph[node]){
                //if the nbr is not yet coloured
                if(color[nbr] == -1){
                    color[nbr] = !color[node];
                    q.push(nbr);
                }
                //if the nbr is already colored with same color
                if(color[nbr] == color[node]){
                    //not bipartite
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V, -1);

        for(int i=0; i<V; ++i){
            if(color[i] == -1){
                if(checkBipartite(i, V, graph, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};


//Approach : DFS
class Solution {
private:
    bool checkBipartiteDFS(int node, int col, vector<int>&color, vector<vector<int>>& graph){
        color[node] = col;

        for(auto nbr : graph[node]){
            if(color[nbr] == -1){
                if(checkBipartiteDFS(nbr, !col, color, graph) == false){
                    return false;
                }
            }
            else if(color[nbr] == color[node]){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V, -1);

        for(int i=0; i<V; ++i){
            if(color[i] == -1){
                if(checkBipartiteDFS(i, 0, color, graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};