//leetcode-242: Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        //Approach-1: Sorintg
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;


        //Approach-2: HashMap
        if(s.size() != t.size()) return false;

        unordered_map<char, int>mpp;

        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        
        for(auto it : mpp) {
            if(it.second != 0) return false;
        }

        return true;


        //Approach-3:HashMap But Array
        int count[26] = {0};
        
        // Count the frequency of characters in string s
        for (char x : s) {
            count[x - 'a']++;
        }
        
        // Decrement the frequency of characters in string t
        for (char x : t) {
            count[x - 'a']--;
        }
        
        // Check if any character has non-zero frequency
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        
        return true;
    }
};