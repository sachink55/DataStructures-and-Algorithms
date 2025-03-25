//leetcode - 516 : Longest Palindromic Subsequence

//Approach : To find the longest palindromic subsequence... Just reverse the string & find the LCS.
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    //LCS Code -> Space Optimized
    int solve(string& a, string& b) {
        vector<int> next(a.length() + 1, 0);
        vector<int> curr(a.length() + 1, 0);

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
            // shifting
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        int ans = solve(s, a);
        return ans;
    }
};