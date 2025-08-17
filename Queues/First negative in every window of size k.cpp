// 

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;
        
        // process first window of size k
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }
        
        // process windows from index k to n - 1
        for (int i = k; i < n; i++) {
            // answer for the previous window
            if (!dq.empty())
                ans.push_back(arr[dq.front()]);
            else
                ans.push_back(0);
            
            // remove out of window elements
            if (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            
            // add current element if negative
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }
        
        // handle the last window
        if (!dq.empty())
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
        
        return ans;
    }
};