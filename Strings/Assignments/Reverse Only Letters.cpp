//leetcode-917: Reverse only letters

//Approach: Two Pointers
//TC: O(n)
//SC: O(1)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l < r){
            if(!isalpha(s[l])) l++;
            else if(!isalpha(s[r])) r--;
            else {
                swap(s[l], s[r]);
                l++; r--;
            }
        }
        return s;
    }
};

//Approach-2: Using Stack
//TC: O(n)
//SC: O(n)

class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        for (char ch : s) 
            if (isalpha(ch))
                st.push(ch);
        

        for (char &ch : s) {
            if (isalpha(ch)) {
                //replace ch char with the top of the Stack 
                //which is the reverse order of char ch
                ch = st.top();
                st.pop();
            }
        }
        return s;
    }
};
