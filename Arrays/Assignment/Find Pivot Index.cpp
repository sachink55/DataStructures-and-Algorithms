//leetcode-724: Find Pivot Index

class Solution {
public:
    /*int Bruteforce(vector<int>&nums){
        for(int i=0; i<nums.size(); i++){
            int lsum =0, rsum=0;
            for(int j=0; j<i; j++){
                lsum += nums[j];
            }
            for(int j= i+1; j<nums.size(); j++){
                rsum += nums[j];
            }
            if(lsum == rsum)
                return i;
        }
        return -1;
    }*/

    int PrefixSumApproach(vector<int>&nums){
        vector<int>lsum(nums.size(), 0);
        vector<int>rsum(nums.size(), 0);

        //Calculate left sum array
        for(int i=1; i<nums.size(); ++i)
            lsum[i] = lsum[i-1] + nums[i-1];
        
        //Calculate right sum array
        for(int i= nums.size()-2; i>=0; --i)
            rsum[i] = rsum[i+1] + nums[i+1];
    
        //Ab check karte hai
        for(int i=0; i<nums.size(); ++i){
            if(lsum[i] == rsum[i]){
                return i;
            }
        }
        return -1;
    }

    int pivotIndex(vector<int>& nums) {
       //return  Bruteforce(nums);
       return PrefixSumApproach(nums);
    }
};