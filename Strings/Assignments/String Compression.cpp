//leetcode-443: String Compression

//TC: O(n), we only traverse array once
//SC: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; 

        for (int i = 0; i < n;) {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                i++;
                count++;
            }

          
            chars[index++] = ch;

            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[index++] = c;
                }
            }
        }

        return index; 
    }
};