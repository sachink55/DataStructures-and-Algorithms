//Kosaraju's Algorithm to find strongly connected components in a graph
//TC : O(V+E)
//SC : O(V)

//Approach:  Perform DFS to get nodes in order of finishing times (topological sort). Reverse the graph and perform DFS again in the order of finishing times to find strongly connected components (SCCs).

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	unordered_map<int,list<int> > adjList;

	void addEdge(int u, int v,bool direction) {
		//direction -> 0 -> undorected
		//direction -> 1 -> directed
		if(direction == 0) {
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		else {
			adjList[u].push_back(v);
		}
	}

	void dfs1(int node, stack<int>& ordering, unordered_map<int,bool>& vis) {
		vis[node] = true;
		for(auto nbr: adjList[node]) {
			if(!vis[nbr]) {
				dfs1(nbr, ordering, vis);
			}
		}
		//wapas aate hue stack me push
		ordering.push(node);
	}
	void dfs2(int src, unordered_map<int,bool>& vis2, unordered_map<int,list<int> >& adjNew) {
		vis2[src] = true;
		cout << src <<"; ";

		for(auto nbr: adjNew[src]) {
			if(!vis2[nbr]) {
				dfs2(nbr, vis2, adjNew);
			}
		}
	}

	int getStronglyConnectedComponents(int n) {
		//step1: get the Ordering
		stack<int> ordering;
		unordered_map<int,bool> vis;

		for(int i=0; i<n; i++ ){
			if(!vis[i]) {
				dfs1(i,ordering,vis);
			}
		}

		//step2: reverse edges
		unordered_map<int, list<int> > adjNew;
		for(auto a: adjList) {
			for(auto b: a.second) {
				int u = a.first;
				int v = b;
				//v -> u ki entry create krni h 
				adjNew[v].push_back(u);
			}
		}
		//step3: traverse using ordering and count components
		int count = 0;
		unordered_map<int,bool> vis2;

		while(!ordering.empty()) {
			int node = ordering.top();
			ordering.pop();
			if(!vis2[node]) {
				cout << "SCC #" << count+1 << ": ";
				dfs2(node, vis2,adjNew);
				count++;
				cout << endl;
			}
		}
		return count;
	}

};

int main() {
	Graph g;
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 0, 1);

	g.addEdge(2, 4, 1);

	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(6, 4, 1);

	g.addEdge(6, 7, 1);

	int n = 8;
    int ans = g.getStronglyConnectedComponents(n);
    cout << "SCC Count: " << ans << endl;
}