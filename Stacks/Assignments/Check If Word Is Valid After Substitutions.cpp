//leetcode-1003: Check If Word Is Valid After Substitutions

//Approach-1: String Manipulation
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    bool isValid(string s) {
        string part = "abc";
        while(s.find(part) != string::npos){
            s.erase(s.find(part), part.length());
        }
        return s.empty();
    }
};


//Approach-2: Using Recursion (Brute Force - Worse than Approach-1. why?)
//TC: O(n^2)
//SC: O(n)
class Solution {
public:
    bool isValid(string s) {
        //base case
        if(s.size()==0) return true;

        if(s.find("abc") != string::npos){
            string tLeft = s.substr(0, s.find("abc"));
            string tRight = s.substr(s.find("abc")+3, s.size());
            //s = tLeft + tRight
            return isValid(tLeft + tRight);
        }

        return false;
    }
};


//Approach-2: Using Stack [Optimal]
//TC: O(n)
//SC: O(n)

class Solution {
public:
    bool isValid(string s) {
        if(s[0] != 'a') return false;

        stack<char> st;
        for (char ch : s) {
            if (ch == 'a') {
                st.push(ch);
            }
            else if (ch == 'b') {
                if (!st.empty() && st.top() == 'a') {
                    st.push(ch);
                }
                else return false;
            }
            else {
                // ch == 'c'
                if (!st.empty() && st.top() == 'b') {
                    st.pop();
                    if (!st.empty() && st.top() == 'a') {
                        st.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }

        return st.empty();
    }
};

