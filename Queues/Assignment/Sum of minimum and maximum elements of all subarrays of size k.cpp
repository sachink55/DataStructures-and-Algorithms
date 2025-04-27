///gfg - Sum of minimum and maximum elements of all subarrays of size k

int sumOfMinMaxOfAllWindowSizeK(vector<int>& nums, int k) {
       int ans = 0;
       deque<int>dq, dq2;

        //first window ko process karo
        for(int i=0; i<k; i++) {
            int element = nums[i];
            //queue ke andar jitne bhi chhote element hai unhe remove kardo
            while(!dq.empty() && element >= nums[dq.back()]){
                dq.pop_back();
            }

            while(!dq2.empty() && element <= nums[dq2.back()]){
                dq2.pop_back();
            }

            //ab insert kardo
            dq.push_back(i);
            dq2.push_back(i);
        }

        ans += nums[dq.front()] + nums[dq2.front()];

        //remaining window ko process karo
        for(int i=k; i<nums.size(); i++){
            //update window
            if(!dq.empty() && i- dq.front() >=k){
                dq.pop_front();
            }

            if(!dq2.empty() && i- dq2.front() >=k){
                dq2.pop_front();
            }

            //chhote elements ko pop kardo
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            while(!dq2.empty() && element < nums[dq2.back()]){
                dq2.pop_back();
            }

            //addition
            dq.push_back(i);
            dq2.push_back(i);

            ans += nums[dq.front()] + nums[dq2.front()];
        }
        
        return ans;
    }

    int main() {
        vector<int> nums = {1, 3, 2, 4, 5};
        int k = 3;
        cout << sumOfMinMaxOfAllWindowSizeK(nums, k) << endl; // Output: 18
        return 0;
    }