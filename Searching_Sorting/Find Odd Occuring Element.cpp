//leetcode - 540 : Single Element in a Sorted Array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            //single element case
            if(s==e)   return nums[s];

            if(mid%2 == 0){
                if(nums[mid] == nums[mid+1]){
                    //go right
                    s = mid + 2;
                }
                else{
                    //right or Ans pe ho
                    e = mid;
                }
            }
            //mid is odd
            else{
                if(nums[mid-1] == nums[mid]){
                    //go right
                    s = mid+1;
                }
                else{
                    //go left
                    e = mid-1;
                }
            }
        }
        return nums[s];
    }
};