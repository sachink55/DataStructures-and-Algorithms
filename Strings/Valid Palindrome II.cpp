//leetcode-680: Valid Palindrome II

class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;

        while(i <= j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                bool ans1 = isPalindrome(s, i+1, j);
                bool ans2 = isPalindrome(s, i, j-1);
                return ans1 || ans2;
            }
        }
        return true;
    }
};