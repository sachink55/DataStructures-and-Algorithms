//leetcode-5: Longest Palindromic Substring

//Approach-1: Check All Substrings
//TC: O(n^3)
//SC: O(1)

class Solution {
public:
    bool check(string &s, int i, int j) {
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        for(int i = n; i > 0; i--) {  // Length of substring
            for(int j = 0; j <= n - i; j++) {  // Start index
                if(check(s, j, j + i - 1)) {  
                    return s.substr(j, i); 
                }
            }
        }
        return "";
    }
};

//...................................................................................................
//Approach-2: DP
//TC: O(n^2)
//SC: O(n^2)

class Solution {
public:
    int maxlen = 1, start = 0;
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

//.............................................................................................................
//Approach-3: Expand from Centres
//TC: O(n^2)
//SC: O(1)

class Solution {
public:
    string expand(int i, int j, string s) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }

        return s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            string odd = expand(i, i, s);
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            string even = expand(i, i + 1, s);
            if (even.size() > ans.size()) {
                ans = even;
            }
        }

        return ans;
    }
};
