//leetcdoe-1047: Remove all adjacent duplicates in a string

class Solution {
public:
    string removeDuplicates(string s) {
        //Approach-1:
        string ans;
        ans.push_back(s[0]);

        for(int i=1; i<s.size(); i++){
            if(ans.size()>=1 && ans.back() == s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;

        //Approach-2: Using Stack
        stack<char>st;
        st.push(s[0]);

        for(int i=1; i<s.size(); i++){
            if(st.size()>=1 && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};