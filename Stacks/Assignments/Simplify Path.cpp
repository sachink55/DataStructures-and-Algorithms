//leetcode-71: Simplify Path

//Approach: Using Stack
//TC: O(n)
//SC: O(n)

class Solution {
public:

    string simplifyPath(string path) {
        stack<string>st;
        int i = 0;
        while(i < path.size()){
            int start = i;
            int end = i+1;
            while(end < path.size() && path[end] != '/'){
                ++end;
            }
            string minPath = path.substr(start, end-start);
            i = end;
            if(minPath=="/" || minPath=="/."){
                continue;
            }
            else if(minPath!="/.."){
                st.push(minPath);
            } 
            else if(!st.empty()){
                st.pop();
            }
        }

        if(st.empty()) return "/";

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};