//leetcode - 983 : Minimum Cost For Tickets

//Approach : DP
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs,vector<int>&dp) {
        // base case
        if (i == days.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        //1 day pass
        int opt1 = costs[0] + solve(i + 1, days, costs, dp);

        //7 days pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) {
            j++;
        }
        int opt2 = costs[1] + solve(j, days, costs, dp);

        //30 days pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30) {
            j++;
        }
        int opt3 = costs[2] + solve(j, days, costs, dp);

        dp[i] = min(opt1, min(opt2, opt3));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        int i = 0;
        return solve(i, days, costs,dp);
    }
};