//gfg - Aggressive Cows 

class Solution {
  public:
    
    bool isPossible(vector<int>&stalls, int k, int mid){
        //can we place k cows, with at least mid distance between them
        
        int cowCount = 1;
        int pos = stalls[0];
        
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - pos >= mid){
                cowCount++;     //one more cow has been placed
                pos = stalls[i];
            }
            if(cowCount==k) return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int start = 0;
        int end = stalls[stalls.size()-1] - stalls[0];
        
        int ans = -1;
        
        while(start <= end){
            int mid = (start + end) >> 1;
            if(isPossible(stalls, k, mid)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};