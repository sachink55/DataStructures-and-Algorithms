//leetcode-28: Find the Index of the First Occurrence in a String

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) == string::npos) return -1;
        
        int n = haystack.size();
        int m = needle.size();
        int ans = -1;

        for(int i=0; i<n; i++){
            int idx = i;
            for(int j=0; j<m; j++){
                if(haystack[i] != needle[j]){
                    i = idx;
                    break;
                }
                else i++;
                if(j == m-1){
                    return idx;
                } 
            }
        }

        return -1;

        //Approach-2:
        //TC: O((n-m)*m)

        if(haystack == needle) return 0;

        int n = haystack.size();
        int m = needle.size();

        if(n < m) return -1;

        for(int i=0; i<=(n-m); i++){
            if(haystack.substr(i, m) == needle)
                return i;
        }

        return -1;

        //Approach-3: Using find()
        return haystack.find(needle);
    }
};