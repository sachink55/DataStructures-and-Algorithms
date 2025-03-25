//Leetcode-721: Accounts Merge

class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } else if (rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int>parent(n);
        vector<int>rank(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;

        unordered_map <string,int> mp;
        for(int i=0; i<n; ++i){
            auto account = accounts[i];
            for(int j=1; j<account.size(); j++){
                string &mail = account[j];
                auto it = mp.find(mail);
                if(it == mp.end()) mp[mail] = i;
                else unionSet(i, it->second, parent, rank);
            }
        }

        unordered_map<int, set<string>> preAns;
        for(auto it : mp){
            int accNo = it.second;
            auto mail = it.first;

            accNo = findParent(parent, accNo);
            preAns[accNo].insert(mail);
        }

        vector<vector<string>>ans;

        for(auto it: preAns){
            auto accNo = it.first;
            auto st = it.second;
            vector<string>v;
            v.push_back(accounts[accNo][0]);
            for(auto &mail: st) v.push_back(mail);
            ans.push_back(v);
        }
        return ans;
    }
};