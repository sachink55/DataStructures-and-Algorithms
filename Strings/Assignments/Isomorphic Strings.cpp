//leetcode-205: Isomorphic Strings

//Approach-1:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return 0;

        vector<int> mp1(256, -1);
        vector<int> mp2(256, -1);
        
        for(int i=0; i<s.size(); i++){
            if(mp1[s[i]] != mp2[t[i]]) return false;
            mp1[s[i]] = i;
            mp2[t[i]] = i;
        }

        return true;
    }
};