//DFS traversal
//TC : O(V+E)
//SC : O(V)

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList; 

    void addEdge(T u, T v, bool direction) {
        if (direction == 1) {
            adjList[u].push_back(v);
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << ": {  ";
            for (T nbr : i.second) {
                cout << nbr << " ";
            }
            cout << "}" << endl;
        }
    }

    void dfs(T src, unordered_map<T, bool> &vis) {
        vis[src] = true;
        cout << src << " ";

        for (auto nbr : adjList[src]) {
            if (!vis[nbr]) {
                dfs(nbr, vis);
            }
        }
    }
};

int main() {
    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('c', 'd', 0);
    g.addEdge('c', 'e', 0);
    g.addEdge('d', 'e', 0);
    g.addEdge('e', 'f', 0);

    unordered_map<char, bool> visited;

    // to ensure dfs for every disconnected component 
    for (auto node : g.adjList) { 
        if (!visited[node.first]) {
            g.dfs(node.first, visited);
            cout << endl;
        }
    }

    return 0;
}
