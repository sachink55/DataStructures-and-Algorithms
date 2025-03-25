//leetcode - 279 : Perfect Squares

//Approach : DP - recursion + Memoization
//T.C : O(n)  since O(n * sqrt(n)) ~ O(n)
//S.C : O(n)

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // base cases
        if (n == 0) return 1;
        if (n < 0) return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;
        int i = 1;
        while (i <= sqrt(n)) {
            int perfectSqr = i * i;
            int numPerfectSqr = 1 + solve(n - perfectSqr, dp);
            if (numPerfectSqr < ans)
                ans = numPerfectSqr;
            ++i;
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp) - 1;
    }
};

//..................................................
//Bottom Up Approach - Tabulation

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        
        dp[0] = 1;

        for(int i=0; i<=n; i++){
            int ans = INT_MAX;
            int start = 1;
            while (start <= sqrt(n)) {
                int perfectSqr = start * start;
                int numPerfectSqr = 1 + dp[n - perfectSqr];
                if (numPerfectSqr < ans)
                    ans = numPerfectSqr;
                ++start;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp) - 1;
    }
};