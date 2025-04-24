//leetcode-921: Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;

        for(char ch: s){
            if(ch=='(') st.push(ch); // simply push '(' into the stack
            else{ 
                //if ch == ')'
                if(!st.empty() && st.top() == '(') st.pop(); //pop if valid bracket
                else st.push(ch); //simply push 

            }
        }
        return st.size();
    }
};