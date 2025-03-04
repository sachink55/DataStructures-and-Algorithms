//leetcode-1: Two Sum

//Using Brute Force
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

//Using Hash Map
//TC: O(n)
//SC: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) == mp.end()){
                mp[nums[i]] = i;
            } 
            else{
                return {mp[target-nums[i]], i};
            }
        }
        return {};
    }
};
