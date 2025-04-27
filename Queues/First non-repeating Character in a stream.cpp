//gfg - Stream First Non-repeating

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        string ans = "";
        queue<char> q;
        int freq[26] = {0};
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            freq[ch-'a']++;
            q.push(ch);
            
            while(!q.empty()){
                char frontChar = q.front();
                if(freq[frontChar-'a'] > 1){
                    q.pop();
                    //ye ans nahi hai
                }
                else{
                    //freq=1 hai
                    ans += frontChar;
                    break;
                }
            }
            
            if(q.empty()) ans += '#';
        }
        
        return ans;
    }
};