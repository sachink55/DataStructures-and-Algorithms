//leetcode-125: Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){
               start++; 
               continue;
            } //checking if first character is alpha numeric and continue if not
           if(!isalnum(s[end])){
               end--;
               continue;
            } // checking if last character is alpha numeric and continue if not
           if(tolower(s[start])!=tolower(s[end]))
                return false;
           else{
               start++;
               end--;
           }
       }
       return true;
    }
};