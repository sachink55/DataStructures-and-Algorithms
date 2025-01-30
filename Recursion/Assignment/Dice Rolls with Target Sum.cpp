//leetcode - 1155 : Number of Dice Rolls With Target Sum

//Approach - 1 : Brute Force (Recursion)
//T.C : O(k^n)
//S.C : O(n)

class Solution{
    public:
    int numRollsToTarget(int n, int k, int target){
        // Base cases
        if (target < 0) return 0; 
        if (n == 0 && target != 0) return 0; 
        if (n != 0 && target == 0) return 0;
        if (n == 0 && target == 0) return 1;

        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans += numRollsToTarget(n-1, k, target-i);
        }

        return ans;
    }
};

//..................................................................................................
//Approach - 2 : DP Memoization 
//T.C : O(target * n * k)
//S.C : O(target * n)

class Solution{
    public:
    const long long MOD = 1e9 + 7; 

    long long solve(int n, int k, int target, vector<vector<long long>> &dp) {
        // Base cases
        if (target < 0) return 0; 
        if (n == 0 && target != 0) return 0; 
        if (n != 0 && target == 0) return 0;
        if (n == 0 && target == 0) return 1;

        // If value is already calculated
        if (dp[n][target] != -1) 
            return dp[n][target];

        long long ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans = (ans + solve(n - 1, k, target - i, dp)) % MOD;
        }

        // Store the result in dp table and return
        return dp[n][target] = ans;
    }

    long long numRollsToTarget(int n, int k, int target) {
        // Initialize 2D DP table
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};
