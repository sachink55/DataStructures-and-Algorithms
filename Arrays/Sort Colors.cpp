//leetcode - 75 : Sort Colors
 
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int i = 0;

        while(i<=right){
            if(nums[i] == 0){
                swap(nums[i], nums[left]);
                left++; i++;
            }
            else if(nums[i]==2){
                swap(nums[i], nums[right]);
                right--;
            }
            else
                i++;
        }
    }
};