//Count the reversals - gfg

//Approach-1:

class Solution {
  public:
    int countMinReversals(string s) {
        //if odd length string, impossible to make it balanced
        if(s.size() & 1) return -1;
        
        stack<char>st;
        for(char ch:s){
            if(ch=='{') st.push(ch);
            else{
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else st.push(ch);
            }
        }
        
        //if stack is still not empty, let's count reversal
        int ans = 0;
        while(!st.empty()){
            char a = st.top(); st.pop();
            char b = st.top(); st.pop();
            if(a==b) ans+= 1;
            else ans+=2;
        }

        return ans;
    }
};

//Approach-2:

class Solution {
  public:
    int countMinReversals(string s) {
        //if odd length string, impossible to make it balanced
        if(s.size() & 1) return -1;
        
        stack<char>st;
        for(char ch:s){
            if(ch=='{') st.push(ch);
            else{
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else st.push(ch);
            }
        }
        
        //if stack is still not empty, let's count reversal
        int opencnt = 0, closecnt = 0;
        
        while(!st.empty()){
            if(st.top() == '{') opencnt++;
            else closecnt ++;
            st.pop();
        }
    
    
        return (opencnt + 1)/2 + (closecnt + 1)/2;
    }
};


//Approach-3:
//Using two counters instead of stack
class Solution {
  public:
    int countMinReversals(string s) {
        //if odd length string, impossible to make it balanced
        if(s.size() & 1) return -1;
        
        int open = 0, close = 0;
        for(char ch:s){
            if(ch=='{') open++;
            else{
                if(open > 0) open--;
                else close++;
            }
        }
        
        return (open + 1)/2 + (close + 1)/2;
    }
};
