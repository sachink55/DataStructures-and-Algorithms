//leetcode -  1130 : Minimum Cost Tree From Leaf Values

//Approach : DP Memoization
//T.C : O(n^3)
//S.C : O(n^2)

class Solution {
public:
    int solveUsingMem(vector<int>&arr, map<pair<int,int>, int>&maxi, int s, int e, vector<vector<int>>&dp){
        //base case
        if(s >= e)
            return 0;
        
        //already exists
        if(dp[s][e] != -1)
            return dp[s][e];

        int ans = INT_MAX;
        for(int i=s; i<e; i++){
            //i is being used here for partitioning
            ans = min(ans, maxi[{s,i}] * maxi[{i+1, e}] + solveUsingMem(arr, maxi, s, i, dp) + solveUsingMem(arr, maxi, i+1, e, dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        //pre-compute maxNode Value between two indexes and store in map
        map<pair<int,int>,int> maxi;
        for(int i=0; i<n; i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        int start  = 0;
        int end  =  n-1;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solveUsingMem(arr, maxi, start, end, dp);
    }
};


//DP Tabulation

class Solution {
public:
    int solveUsingTabulation(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int start = n-1; start >= 0; start--) {
            for (int end = start+1 ; end <= n-1; end++) {

                int ans = INT_MAX;
                for (int i = start; i < end; i++) {
                    // i is being used here for partitioning
                    ans = min(ans, maxi[{start, i}] * maxi[{i + 1, end}] + dp[start][i] + dp[i+1][end]);
                }
                dp[start][end] = ans;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        // pre-compute maxNode Value between two indexes and store in map
        map<pair<int, int>, int> maxi;
        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        return solveUsingTabulation(arr, maxi);
    }
};