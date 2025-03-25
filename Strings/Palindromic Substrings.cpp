//leetcode-647: Palindromic Substrings

//Approach-1:
//TC: O(n^2)
//SC: O(1)

class Solution {
public:
    int expand(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.size() && s[i] == s[j]){
            count++; i--; j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        for(int i=0; i<s.size(); i++){
            //odd length ka
            int j = i;
            totalCount += expand(s, i, j);

            //even length ka
            j = i+1;
            totalCount += expand(s, i, j);
        }
        
        return totalCount;
    }
};

//........................................................................................
//Approach-2: DP
//TC: O(n^2)
//SC: O(n^2)


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, 0));
        //dp - stores whether string from index i to j is palindrome or not

        int count = 0;
        for(int i = n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                //length one
                if(i==j) dp[i][j] = true;

                //length two
                else if(j == i+1 && s[i] == s[j]) {
                    dp[i][j] = true;
                }

                else{
                    if((s[i] == s[j]) && dp[i+1][j-1] == 1){
                        dp[i][j] = true;
                    }
                }
                
                if(dp[i][j]) count++;
            }
        }

        return count;
    }
};