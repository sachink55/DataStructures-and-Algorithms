//Shortest Path using BFS (Unweighted Graph) 
//single source shortest path

#include<bits/stdc++.h>
using namespace std;

void shortestPathBFS(int src, vector<vector<int>>& adjList, int V) {
    vector<int> dist(V, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto nbr : adjList[node]) {
            // If a shorter path is found
            if (dist[node] + 1 < dist[nbr]) {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
        }
    }

    // Print the shortest dists
    for (int i = 0; i < V; ++i) {
        cout << "Shortest dist from node " << src << " to node " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int V = 5; 
    vector<vector<int>> adjList(V);

    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(3);
    adjList[3].push_back(4);

    int src = 0; 

    shortestPathBFS(src, adjList, V);

    return 0;
}


//Shortest path from a given source to a destination node

class Graph{
	public:
		unordered_map<int,list<int> > adj;

	void addEdge(int u, int v, bool direction) {
		if(direction == 1) {
			adj[u].push_back(v);
		}
		else {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	void printAdjList() {
		for(auto i: adj) {
			cout << i.first << ": {";
			for(auto j: i.second) {
				cout << j <<",";
			}
			cout <<"}" << endl;
		}
	}

	void shortestPathBfs(int src, int dest) {
		queue<int> q;
		map<int,bool> visited;
		map<int,int> parent;

		//initial state
		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();

			for(auto nbr: adj[frontNode]) {
				if(!visited[nbr]) {
					q.push(nbr);
					parent[nbr] = frontNode;
					visited[nbr] = true;
				}
			}
		}

		//parent array tyar hoga 
		vector<int> ans;
		while(dest != -1) {
			ans.push_back(dest);
			dest = parent[dest];
		}

		reverse(ans.begin(), ans.end());
		//printig the shortest path
		for(auto i: ans) {
			cout << i <<" ";
		}
		
	}
};

int main() {

	Graph g;
	g.addEdge(0, 5, 0);
	g.addEdge(5, 4, 0);
	g.addEdge(4, 3, 0);
	g.addEdge(0, 6, 0);
	g.addEdge(6, 3, 0);
	g.addEdge(0, 1, 0);
	g.addEdge(1, 2, 0);
	g.addEdge(2, 3, 0);

	int src = 0;
	int dest = 3;

	g.shortestPathBfs(src, dest);

	return 0;
}