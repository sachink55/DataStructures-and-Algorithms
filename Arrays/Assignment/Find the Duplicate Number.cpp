//leetcode-287: Find the Duplicate Number

//Approach-1: 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return -1;
    }
};

//Approach-2 : 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //visited Solution
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
         int   index = abs(nums[i]);

            //already visited
            if(nums[index]<0){
                ans = index;
                break;
            }

            // visited mark
            nums[index] *= -1;
        }
        return ans;
    }
};


//Approach-3: 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Floyd's Tortoise and Hare Algorithm (for Cycle Detection)
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};