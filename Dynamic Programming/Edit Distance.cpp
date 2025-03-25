//leetcode - 72 : Edit Distance

//Approach - 1 : DP Memoization
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    int solveUsingMem(string& a, string& b, int i, int j,
                      vector<vector<int>>& dp) {
        // base case
        if (j == b.length())
            return a.length() - i;
        if (i == a.length())
            return b.length() - j;

        // already exists
        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j])
            return solveUsingMem(a, b, i + 1, j + 1, dp);

        int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
        int remove = 1 + solveUsingMem(a, b, i + 1, j, dp);

        dp[i][j] = min(replace, min(insert, remove));
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int i=0, j=0;
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        return solveUsingMem(word1, word2, i, j, dp);
    }
};

//TABULATION
class Solution {
public:
    int solveUsingTabulation(string& a, string& b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));

        for (int row = 0; row <= a.length(); row++) {
            dp[row][b.length()] = a.length() - row;
        }
        for (int col = 0; col <= b.length(); col++) {
            dp[a.length()][col] = b.length() - col;
        }

        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j])
                    ans = dp[i + 1][j + 1];
                else {
                    int replace = 1 + dp[i + 1][j + 1];
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][j];

                    ans = min(replace, min(insert, remove));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        return solveUsingTabulation(word1, word2);
    }
};

//Space Optimisation
//T.C : O(m*n)
//S.C : O(m)

class Solution {
public:
    int solveUsingTabulationSO(string& a, string& b) {
        vector<int> next(a.length() + 1, 0);
        vector<int> curr(a.length() + 1, 0);

        // last column -- jaruri hai
        for (int row = 0; row <= a.length(); row++) {
            next[row] = a.length() - row;
        }

        for (int j = b.length() - 1; j >= 0; j--) {
            //Har naye column ke last dabbe me ans insert karo
            curr[a.length()] = b.length() - j;

            for (int i = a.length() - 1; i >= 0; i--) {
                int ans = 0;
                if (a[i] == b[j])
                    ans = next[i + 1];
                else {
                    int replace = 1 + next[i + 1];
                    int insert = 1 + next[i];
                    int remove = 1 + curr[i + 1];
                    ans = min(replace, min(insert, remove));
                }
                curr[i] = ans;
            }
            // shifting
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        return solveUsingTabulationSO(word1, word2);
    }
};