//gfg - Knapsack with duplicate items - repetition of items allowed

class Solution{
public:
    int solve(int i, int W, int val[], int wt[], vector<vector<int>>&dp){
        //base case
        //last item bacha hai, jitna utha sakte ho, utha lo.
        if(i==0){
            return (int)(W/wt[0]) * val[0];
        }
        
        //if already calculated
        if(dp[i][W] != -1){
            return dp[i][W];
        }
        int incl = 0;
        if(wt[i] <= W){
            incl = val[i] + solve(i, W-wt[i], val, wt, dp);
        }
        int excl = solve(i-1, W, val, wt, dp);
        
        return dp[i][W] = max(incl, excl);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return solve(N-1, W, val, wt, dp);
    }
};