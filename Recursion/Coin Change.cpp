//leetcode-322 : Coin Change

//Approach - 1 : Using Recursion
//T.C. : O(n^k)  where n - no. of different coins and k - amount 
//S.C  : O(n)

class Solution {
public:
    int solve(vector<int>&coins , int amount){
        if(amount==0)   return 0;
        if(amount < 0)  return INT_MAX;

        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); ++i){

            int coin = coins[i];
            //if coin <= amount, then we will proceed further
            if(coin <= amount){
                  int recAns = solve(coins, amount-coin);

                  if(recAns != INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(ans, mini);
                  }
            }
        }
        return mini;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

//Approach - 2 : DP
//T.C : O(n * amount)
//S.C : O(amount)

class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>&dp) {
        if (amount == 0)
            return 0;
        
        if(dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); ++i) {

            int coin = coins[i];
            // if coin <= amount, then we will proceed further
            if (coin <= amount) {
                int recAns = solve(coins, amount - coin, dp);

                if (recAns != INT_MAX) {
                    int ans = 1 + recAns;
                    mini = min(ans, mini);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int>dp(n+1,-1);

        int ans = solve(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

//Approach - 3 : DP Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int val = 1; val <= amount; ++val) {
            for (int coin : coins) {
                if (val >= coin && dp[val - coin] != INT_MAX) {
                    dp[val] = min(dp[val], 1 + dp[val - coin]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
