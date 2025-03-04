//gfg - Book Allocation

class Solution {
  public:
    bool isPossible(vector<int>&arr, int n, int k, int sol){
        int pageSum = 0;
        int studentCount = 1;
        
        for(int i=0; i<n; i++){
            if(arr[i] > sol){
                return false;
            }
            if(pageSum + arr[i] > sol){
                studentCount++;
                pageSum = arr[i];
                if(studentCount > k) return false;
            }
            else{
                pageSum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1;
        
        int s = 0;
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        while(s <= e){
            int mid = (s+e)/2;
            if(isPossible(arr, n, k, mid)){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};