//leetcode-394 : Decode String

//Approach: Using Stack
//TC: O(n)
//SC: O(n)

class Solution {
public:

    string decodeString(string s) {
        //Approach-1: Using Stack - O(n)
        stack<string> st;
        for(char ch : s) {
            if(ch == ']') {
                string stringToRepeat = "";
                while(!st.empty() && st.top() != "[") {
                    string top = st.top(); st.pop();
                    stringToRepeat = top + stringToRepeat;  //order
                }
                st.pop();  // Remove '['

                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    numericTimes = st.top() + numericTimes;  //order
                    st.pop();
                }
                int n = stoi(numericTimes);

                string currentDecode = "";
                while(n--) {
                    currentDecode += stringToRepeat;
                }
                st.push(currentDecode);
            }
            else {
                st.push(string(1, ch));
                //creates a string of length 1 containing the character ch
                //bcz stack ko string chahiye 
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;   //order  
            st.pop();
        }
        return ans;
    }
};


//Approach-2: Using Recursion
//TC: O(n)
//SC: O(n)

class Solution {
public:
    string decodeHelper(string &s, int &i){
        string ans = "";
        int n = 0;

        while(i < s.size()){
            char ch = s[i];
            if(isdigit(ch)){
                n = n*10 + ch-'0';
            }
            else if(ch=='['){
                string temp = decodeHelper(s, ++i);
                while(n--) ans += temp;
                n = 0;
            }
            else if(ch==']'){
                return ans;
            }
            else{
                ans += ch;
            }
            i++;
        }
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeHelper(s, i);
    }
};

