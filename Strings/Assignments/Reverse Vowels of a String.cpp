//leetcode-245: Reverse Vowels of a String

class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l <= r){
            if(!isVowel(s[l])) l++;
            else if(!isVowel(s[r])) r--;
            else{
                swap(s[l], s[r]);
                l++; r--;
            }
        }
        return s;
    }
};