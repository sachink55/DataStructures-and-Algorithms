//leetcode - 44 : WildCard Matching

//Approach - 1 : Simple Recursion (TLE Dega)
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:
    bool patternMatch(string &s, string &p, int i, int j) {
        // base 
        if (i == s.size() && j == p.size()) {
            return true;
        }

        // pattern over but not string 
        if (j >= p.size()) {
            return false;
        }

        //single char matching
        if (i < s.size() && (p[j] == s[i] || p[j] == '?')) {
            return patternMatch(s, p, i + 1, j + 1);
        }

        if (p[j] == '*') {
            //two options : 
            //1. skip the * and move to the next pattern char
            //2. let '*' consume 1 char of s 
            for (int k = i; k <= s.size(); k++) {
                if (patternMatch(s, p, k, j + 1)) {
                    return true;
                }
            }
            return false;
        }

        // no match
        return false;
    }

    bool isMatch(string s, string p) {
        return patternMatch(s, p, 0, 0);
    }
};


//Approach - 2 : 
//T.C :
//S.C :
