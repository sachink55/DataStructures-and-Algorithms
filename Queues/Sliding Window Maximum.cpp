//leetcdoe-239: Sliding Window Maximum

//TC: O(n)
//SC: O(k) + O(n) = O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> ans;
       deque<int>dq;
        //first window ko process karo
        for(int i=0; i<k; i++) {
            int element = nums[i];
            //queue ke andar jitne bhi chhote element hai unhe remove kardo
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            //ab insert kardo
            dq.push_back(i);
        }

        //remaining window ko process karo
        // removal and addition
        for(int i=k; i<nums.size(); i++){
            // ans store
            ans.push_back(nums[dq.front()]);

            //removal 
            //out of range elements
            if(!dq.empty() && i- dq.front() >=k){
                dq.pop_front();
            }
            //chhote elements ko pop kardo
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            //addition
            dq.push_back(i);
        }
        //last window ka ans store karlo
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};