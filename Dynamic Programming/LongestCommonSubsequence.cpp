//leetcode - 1143 : Longest Common Subsequence

//Approach - 1 : Using Recursion
//T.C : O(2^(m+n))
//S.C : O(m+n)

int solveUsingRecursion(string a, string b, int i, int j){
    //base case
    if(i >= a.length() || j >= b.length())
        return 0;
    
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solveUsingRecursion(a, b, i+1, j+1);
    else
        ans = max(solveUsingRecursion(a, b, i+1, j), solveUsingRecursion(a, b, i, j+1));

    return ans;
}

//...........................................................
//Approach - 2 : DP Memoization
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i >= a.length() || j >= b.length())
            return 0;

        // already exists
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        } else {
            ans = max(solveUsingMem(a, b, i, j + 1, dp), solveUsingMem(a, b, i + 1, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0, j = 0;
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));

        return solveUsingMem(text1, text2, i, j, dp);
    }
};

//Tabulation 

class Solution {
public:
    int solveUsingTabulation(string& a, string& b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                int ans = 0;
                if(a[i] == b[j]) 
                    ans = 1 + dp[i + 1][j + 1];
                else 
                    ans = max(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solveUsingTabulation(text1, text2);
    }
};

//Space Optimisation
//T.C : O(m*n)
//S.C : O(m)

class Solution {
public:
    int solveUsingTabulationSO(string& a, string& b) {
        vector<int>next(a.length()+1, 0);
        vector<int>curr(a.length()+1, 0);

     for (int j = b.length() - 1; j >= 0; j--) {    
        for (int i = a.length() - 1; i >= 0; i--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + next[i + 1];
                } else {
                    ans = max(next[i], curr[i + 1]);
                }
                curr[i] = ans;
            }
            //shift
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solveUsingTabulationSO(text1, text2);
    }
};