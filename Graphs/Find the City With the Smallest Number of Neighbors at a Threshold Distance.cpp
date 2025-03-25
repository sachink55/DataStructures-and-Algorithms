//leetcode-1334 : Find the City With the Smallest Number of Neighbors at a Threshold Distance
//Approach: Dijkstra's Algorithm

class Solution {
public:
    int Dijkstra(int src, int n, unordered_map<int, list<pair<int,int>>>&adjList, int &distThreshold) {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert({0, src});
        
        int reachableCities = 0; //cities at most having distanceThreshold distance

        while (!st.empty()) {
            auto top = st.begin();
            int nodeDist = top->first;
            int node = top->second;
            st.erase(top); // Remove the current node from the set

            if(node != src && nodeDist <= distThreshold)
                ++reachableCities;
            
            // Skip if a shorter path to u has already been found
            if (nodeDist > dist[node]) continue;
            
            for (auto [nbr, wt] : adjList[node]) {
                if (dist[nbr] > dist[node] + wt) {
                    //remove the old entry first
                    st.erase({dist[nbr], nbr}); 
                    
                    // Update distance and add to the set
                    dist[nbr] = dist[node] + wt;
                    st.insert({dist[nbr], nbr});
                }
            }
        }

        return reachableCities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int,int>>> adjList;

        for(auto edge : edges){
            int &u = edge[0];
            int &v = edge[1];
            int &wt = edge[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        int city = 0;
        int minReachableCities = INT_MAX;
        for(int u=0; u<n; ++u){
            int reachableCitiesCount = Dijkstra(u, n, adjList, distanceThreshold);
            if(reachableCitiesCount <= minReachableCities){
                minReachableCities = reachableCitiesCount;
                city = u;
            }
        }
        return city;
    }
};