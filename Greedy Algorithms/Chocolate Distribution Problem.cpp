//gfg - Chocolate Distribution Problem


//Approach-1: Sliding Window
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        //Approach-1: Sliding window
        int n = a.size();
        sort(a.begin(), a.end());
        int minDiff = INT_MAX;
        
        int start, end;
        for(int i=0; i<=(n-m); i++){
            int start = i;
            int end = i + (m-1);
            //start to end - maintaining a window of size m
            
            int diff =a[end] - a[start];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};

//Approach-2: Greedy Algo
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        for(int i=0;i<a.size()-m+1;i++)
        {
            ans=min(ans,a[i+m-1]-a[i]);
        }
        return ans;
    }
};