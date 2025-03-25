//leetcode - 416 : Partition Equal Subset Sum

//Approach : DP Memoization
//T.C : O(n * totalSum)
//S.C : O(n * totalSum)

class Solution {
public:
    bool solveMem(vector<int>& nums, int index, int sum, int target, vector<vector<int>>& dp) {
        // base case
        if (index >= nums.size() || sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }
        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }
        bool include = solveMem(nums, index + 1, sum + nums[index], target, dp);
        bool exclude = solveMem(nums, index + 1, sum, target, dp);

        return dp[index][sum] = (include || exclude);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if (totalSum & 1) {
            //odd cannot be partioned
            return false;
        }
        int target = totalSum / 2;
        int index = 0;
        int sum = 0;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solveMem(nums, index, sum, target, dp);
    }
};

//DP Tabulation

class Solution {
public:
    bool solveTabulation(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        for(int row=0; row<=n; row++){
            dp[row][target] = 1;
        }
        for(int i = n-1; i>=0; i--){
            for(int s = target; s>=0; s--){
                int include = 0;
                if(s + nums[i] <= target)
                    include  = dp[i+1][s+nums[i]];
                int exclude  = dp[i+1][s];
                dp[i][s] = include || exclude;
            }
        }
        return dp[0][0];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if (totalSum & 1) {
            //odd cannot be partioned
            return false;
        }
        int target = totalSum / 2;
        return solveTabulation(nums,target);
    }
};

//Space Optimised
//T.C : O(n * totalSum)
//S.C : O(totalSum)

class Solution {
public:
    bool solveTabulationSO(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>next(target+1, 0);
        vector<int>curr(target+1, 0);

        next[target] = 1;
        curr[target] = 1;
        
        for(int i = n-1; i>=0; i--){
            for(int s = target; s>=0; s--){
                int include = 0;
                if(s + nums[i] <= target)
                    include  = next[s+nums[i]];
                int exclude  = next[s];
                curr[s] = include || exclude;
            }
            //shifting
            next = curr;
        } 
        return next[0];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if (totalSum & 1) {
            return false;
        }
        int target = totalSum / 2;
        return solveTabulationSO(nums,target);
    }
};