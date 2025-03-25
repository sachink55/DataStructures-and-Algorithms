//leetcode - 712 :  Minimum ASCII Delete Sum for Two Strings

//T.C : O(m * n)
//S.C : O(m * n)

class Solution {
public:
    //Memoization
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        int cost = 0;
        if(i == s1.size() || j == s2.size()){
            //return the sum of ASCII of remaining char of remaining string
            for(int x=i; x<s1.size(); x++) cost += s1[x];
            for(int x=j; x<s2.size(); x++) cost += s2[x];
            return cost;
        }
        
        //already exists
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            cost = solve(s1, s2, i+1, j+1, dp);
        }
        else{
            int cost1 = s1[i] + solve(s1, s2, i+1, j, dp);
            int cost2 = s2[j] + solve(s1, s2, i, j+1, dp);
            cost = min(cost1, cost2);
        }
        return dp[i][j] = cost;
    }

    //Tabulation
    int solveBU(string &s1, string &s2){
        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        //Initialize base cases when one of the string is empty

        for(int i=s1.size()-1; i>=0; --i){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }
        for(int j=s2.size()-1; j>=0; --j){
            dp[s1.size()][j] = s2[j] + dp[s1.size()][j+1];
        }

        for(int i=s1.size()-1; i>=0; --i){
            for(int j=s2.size()-1; j>=0; --j){
                int cost = 0;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];
                }
                else{
                    int cost1 = s1[i] + dp[i+1][j];
                    int cost2 = s2[j] + dp[i][j+1];
                    cost = min(cost1, cost2);
                }
                dp[i][j] = cost;
            }
        }
        return dp[0][0];
    }
    
    int minimumDeleteSum(string s1, string s2) {
        // int i=0,j=0;
        // vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        // return solve(s1, s2, i, j, dp);
        return solveBU(s1, s2);
    }
};