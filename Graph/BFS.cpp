//BFS Traversal of a graph using adjacency list representation
//TC : O(V+E)
//SC : O(V)

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;

     void addEdge(T u, T v, bool dir){
        adjList[u].push_back(v);
        if(dir){
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << ": { ";
            for (T nbr : i.second) {
                cout << nbr << " ";
            }
            cout << "}" << endl;
        }
    }

    void bfs(T src, unordered_map<T, bool> &vis) {
        queue<T> q;
        q.push(src);
        vis[src] = true; 

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " ";

            for (T nbr : adjList[node]) {
                if (!vis[nbr]) { 
                    q.push(nbr);
                    vis[nbr] = true; 
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    unordered_map<int, bool> visited; 
    cout << "BFS Traversal starting from node 0:" << endl;
    g.bfs(0, visited);

    return 0;
}
