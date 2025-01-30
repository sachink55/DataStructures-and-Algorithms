//leetcode - 5 : Longest Palindromic Substring

//T.C : O(n^3)
//S.C : O(n^2)

class Solution {
public:
    int maxlen = 1, start = 0;
    //solve func time depends on j-i, in worst case it will be O(n)
    bool solve(string& s, int i, int j, vector<vector<int>>&dp) { 
        // base case
        if (i >= j) {
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool flag = false;
        if (s[i] == s[j]) {
            flag = solve(s, i + 1, j - 1, dp);
        }
        if (flag) {
            int currLen = j - i + 1;
            if (currLen > maxlen) {
                maxlen = currLen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool t = solve(s, i, j, dp);
            }
        }
        return s.substr(start, maxlen);
    }
};