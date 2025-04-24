//The Celebrity Problem - gfg

//Approach-1: Brute Force 
//TC: O(N^2)
//SC: O(1)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
    
        for(int i = 0; i < n; i++){
            int knownByEveryone = 0;
            int knowsSomeone = 0;

            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    //i knows j, i is not a celebrity
                    knowsSomeone++;
                }
                if(mat[j][i] == 1){
                    //i known by j
                    knownByEveryone++;
                } 
            }
            
            // Check if the current person 'i' known by everyone else
            if(knowsSomeone == 0 && knownByEveryone == n - 1) {
                return i;
            }
        }
    
        return -1; // No celebrity found
    }
};


//Approach-2: Using Stack
//TC: O(N)
//SC: O(N)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        //Using stack
        int n = mat.size();
        //step1: push all people in the stack
        stack<int>st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        //step2: run a discard method to get mightBeCelebrity
        while(st.size()!=1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(mat[a][b]){
                //a knows b, a is not a celebrity BUT b might be.
                st.push(b);
            }
            //b knows a
            else{
                st.push(a);
            }
        }
        
        int mightBeCeleb = st.top(); st.pop();
        
        //check1: celeb don't know anyone so sare rows 0 honge except diagonal.
        for(int i=0; i<n; i++){
            if(i!=mightBeCeleb && mat[mightBeCeleb][i] != 0) return -1;
        }
        
        //check2: everyone knows celeb, means sare column 1
        for(int j=0; j<n; j++){
            if(j!=mightBeCeleb && mat[j][mightBeCeleb] != 1) return -1;
        }
        
        //mightBeCeleb is the Celebrity
        return mightBeCeleb;
    }
};
