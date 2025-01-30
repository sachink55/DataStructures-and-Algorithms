// Graph class- 1 : Basic terms, Adjacency matrix, Adjacency Lists, Bfs, Dfs

//Adjacency Matrix
// void adjMatrix(vector<pair<int, int>>edge_list){
//     int n = edge_list.size();
//     vector<vector<int>> adj(n, vector<int>(n,0));

//     for(auto i : edge_list){
//         int u = i.first;
//         int v = i.second;
//         adj[u][v] = 1;
//     }
// }

#include <iostream>
#include <unordered_map>
#include <list>
#include<queue>

using namespace std;

//Adjacency lists
template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjlist;

    void addEdge(T u, T v, bool dir) {
        // dir -> 0 : undirected
        // dir -> 1 : directed
        adjlist[u].push_back(v);
        if (dir == 0) {
            adjlist[v].push_back(u);
        }
    }

    void print() {
        for (auto& i : adjlist) {
            cout << i.first << " : { ";
            for (T nbr : i.second) {
                cout << nbr << ", ";
            }
            cout << "}";
            cout << endl;
        }
    }

    //bfs
    void bfsTraversal(T src,unordered_map< T, bool>& vis) {
      //adjList alrady data member me hai 
      //visited
      
      //queue
      queue<T> q;

      //initial state
      q.push(src);
      vis[src] =true;

      while(!q.empty()) {
        T frontNode = q.front();
        cout << frontNode << " ";
        q.pop();

        //go to nbr
        for(auto nbr: adjList[frontNode]) {
          T nbrData = nbr.first;

          if(!vis[nbrData]) {
            q.push(nbrData);
            vis[nbrData] = true;
          }
        }
      }
    }


    //dfs
    void dfs(T src, unordered_map<T,bool>& vis ) {
      vis[src] = true;
      cout << src << " ";

      for(auto nbr: adjList[src]) {
        T nbrData = nbr.first;
        if(!vis[nbrData]) {
          dfs(nbrData, vis);
        }
      }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);

    g.print();
    return 0;
}


