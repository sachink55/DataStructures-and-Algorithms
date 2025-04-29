//leetcode-209: Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int start = 0, sum = 0;

        for(int end = 0; end < n; end++){
            sum += nums[end];

            while(sum >= target){
                minLength = min(minLength, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};
