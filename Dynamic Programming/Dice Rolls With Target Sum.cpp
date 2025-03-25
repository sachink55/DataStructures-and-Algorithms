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
    const long long int MOD = 1e9 + 7; 

    int solve(int n, int k, int target, vector<vector<int>> &dp) {
        // Base cases
        if (target < 0) return 0; 
        if (n == 0 && target != 0) return 0; 
        if (n != 0 && target == 0) return 0;
        if (n == 0 && target == 0) return 1;

        // If value is already calculated
        if (dp[n][target] != -1) 
            return dp[n][target];

        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans = (ans %MOD + solve(n - 1, k, target - i, dp) %MOD) % MOD;
        }

        // Store the result in dp table and return
        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        // Initialize 2D DP table
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};

//.........................................................................................
//Approach : Same Same but different. More intuitive and more starightforward
//T.C : O(target * n * k)
//S.C : O(n*target)

//DP Memoization
class Solution{
    public:
    long long int MOD = 1000000007;
    int solveMem(int n, int k, int target, int diceUsed, int currSum, vector<vector<int>> &dp){
        //Base cases
        if(diceUsed == n && currSum == target)
            return 1;
        if(diceUsed == n && currSum != target)
            return 0;
        if(diceUsed != n && currSum == target)
            return 0;

        //If value already exists
        if(dp[diceUsed][currSum] != -1){
            return dp[diceUsed][currSum];
        }

        int ans = 0;
        for(int face=1; face<=k; face++){
            int recAns = 0;
            if(currSum + face <= target){
                recAns = solveMem(n, k, target, diceUsed+1, currSum+face, dp);
            }
            ans = (ans %MOD + recAns %MOD) %MOD;
        }
        dp[diceUsed][currSum] = ans;
        return dp[diceUsed][currSum];
    }

    int numRollsToTarget(int n, int k, int target){
        int diceUsed = 0;
        int currSum = 0;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solveMem(n, k, target, diceUsed, currSum, dp);
    }
};


//DP Tabulation

class Solution{
    public:
    long long int MOD = 1000000007;
    int solveUsingTabulation(int n, int k, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        dp[n][target] = 1;

        for(int dice = n-1; dice>=0; dice--){
            for(int sum = target; sum>=0; sum--){
                int ans = 0;
                for(int face=1; face<=k; face++){
                    int recAns = 0;
                    if(sum + face <= target){
                        recAns = dp[dice+1][sum+face];
                    }
                    ans = (ans %MOD + recAns %MOD) %MOD;
                }
                dp[dice][sum] = ans;
            }
        }
       return dp[0][0];
    }

    int numRollsToTarget(int n, int k, int target){
        return solveUsingTabulation(n, k, target);
    }
};

//Space Optimised
//T.C : O(n * k * target)
//S.C : O(target)

class Solution{
    public:
    long long int MOD = 1000000007;
    int solveUsingTabulationSO(int n, int k, int target){
        vector<int> next(target+1, 0);
        vector<int> curr(target+1, 0);
        
        next[target] = 1;

        for(int dice = n-1; dice>=0; dice--){
            for(int sum = target; sum>=0; sum--){
                int ans = 0;
                for(int face=1; face<=k; face++){
                    int recAns = 0;
                    if(sum + face <= target){
                        recAns = next[sum+face];
                    }
                    ans = (ans %MOD + recAns %MOD) %MOD;
                }
                curr[sum] = ans;
            }
            //shifting
            next = curr;
        }
       return next[0];
    }

    int numRollsToTarget(int n, int k, int target){
        return solveUsingTabulationSO(n, k, target);
    }
};
