//leetcode - 375 : Guess Number Higher or Lower II

//Approach : DP Memoization
//T.C : O(n^3)
//S.C : O(n^2)

class Solution {
public:
    int solveMem(int start, int end, vector<vector<int>>&dp){
        //base case
        if(start >= end)
            return 0;

        //already exists
        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i + max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end  = n;
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return solveMem(start, end, dp);
    }
};

//DP Tabulation

class Solution {
public:
    int solveTabulation(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+1,0));
        
        for(int start = n; start>=1; start--){
            for(int end = start+1; end <= n; end++){
                int ans = INT_MAX;
                for(int i=start; i<=end; i++){
                    ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return solveTabulation(n);
    }
};