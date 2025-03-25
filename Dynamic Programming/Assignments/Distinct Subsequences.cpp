//leetcode - 115 : Distinct Subsequences

//T.C : O(m * n)
//S.C : O(m * n)

class Solution {
public:
    // Top Down - Memoization
    int solveTD(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (s[i] == t[j])
            ans += solveTD(s, t, i + 1, j + 1, dp);
        ans += solveTD(s, t, i + 1, j, dp);
        return dp[i][j] = ans;
    }

    //Bottom Up - Tabulation
    int solveBU(string& s, string& t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i=0; i<=s.size(); i++){
            dp[i][t.size()] = 1;
        }
      
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = t.size() - 1; j >= 0; --j) {
                long long ans = 0;
                if (s[i] == t[j])
                    ans += dp[i + 1][j + 1];
                ans += dp[i + 1][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    //Space Optimization
    //T.C : O(m*n)
    //S.C : O(n)

    int solveSO(string &s, string &t){
        vector<int>nextRow(t.size()+1, 0);
        vector<int>currRow(t.size()+1, 0);

        for (int i = s.size() - 1; i >= 0; --i) {
            nextRow[t.size()] = 1;
            for (int j = t.size() - 1; j >= 0; --j) {
                long long ans = 0;
                if (s[i] == t[j])
                    ans += nextRow[j + 1];
                ans += nextRow[j];
                currRow[j] = ans;
            }
            //shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int numDistinct(string s, string t) {
        // vector<vector<int>>dp (s.size()+1, vector<int>(t.size()+1, -1));
        // return solveTD(s, t, 0, 0, dp);
        // return solveBU(s, t);
        return solveSO(s, t);
    }
};