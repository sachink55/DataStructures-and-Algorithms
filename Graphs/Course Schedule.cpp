//leetcode-207 : Course Schedule

//Approach: Topological Sort using BFS 
//Implementation of Detect a cycle in a directed graph using BFS

class Solution {
public:
    void topSortBfs(int n, vector<int>& topoOrder, unordered_map<int, list<int>>&adj) {
		queue<int> q;
		map<int,int> indegree;
		
		//initialise kardo indegree se sare nodes ko
		for( auto i : adj) {
			for(auto nbr: i.second) {
				indegree[nbr]++;
			}
		}
		//push all zero indegree wali node into queue
		for(int node=0; node<n; node++) {
			if(indegree[node] == 0) {
				q.push(node);
			}
		}

		//BFS chalate hai
		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();
			topoOrder.push_back(frontNode);

			for(auto nbr: adj[frontNode]) {
				indegree[nbr]--;

				//check for zero
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

       unordered_map<int, list<int>>adj;
        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }

        vector<int> topo;
        topSortBfs(numCourses, topo, adj);

        return numCourses == topo.size();
    }
};



//Course Schedule - II : Leetcode-210
//It is same as above question, just we have to return the topological order of the courses.

class Solution {
public:
    void topSortBfs(int n, vector<int>& topoOrder, unordered_map<int, list<int>>&adj) {
		queue<int> q;
		map<int,int> indegree;
		
		//initialise kardo indegree se sare nodes ko
		for( auto i : adj) {
			for(auto nbr: i.second) {
				indegree[nbr]++;
			}
		}
		//push all zero indegree wali node into queue
		for(int node=0; node<n; node++) {
			if(indegree[node] == 0) {
				q.push(node);
			}
		}

		//BFS chalate hai
		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();
			topoOrder.push_back(frontNode);

			for(auto nbr: adj[frontNode]) {
				indegree[nbr]--;

				//check for zero
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int, list<int>>adj;
        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }

        vector<int> topo;
        topSortBfs(numCourses, topo, adj);

        if(numCourses == topo.size()){
            return topo;
        }
        else
            return {};
    }
};