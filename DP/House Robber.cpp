//leetcode -198 : House Robber

//Approch-1 : Recursion
//T.C : O(2^n)
//S.C : O(n)

class Solution {
public:

    int solve(vector<int>& nums, int size, int index){
        //base case
        if(index >= size) return 0;

        //robbing at ith index
        int opt1 = nums[index] + solve(nums, size, index+2);

        //not robbing at ith index
        int opt2 = 0 + solve(nums, size, index+1);

        int ans = max(opt1, opt2);

        return ans;
    }

    int rob(vector<int>& nums) {
        int ans = solve(nums, nums.size(), 0);
        return ans;
    }
};

//............................................................
//Approach - 2 : DP 
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int solve(int i, vector<int>&nums, vector<int>&dp){
        //base case
        if(i >= nums.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];
        
        int opt1 = nums[i] + solve(i+2, nums, dp);
        int opt2 = solve(i+1, nums, dp);

        dp[i] = max(opt1, opt2);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int>dp(n+1, -1);

        return solve(0, nums, dp);
    }
};

//DP Tabulation

class Solution {
public:
    int solve(int i, vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n+2, 0);
        //why n+2? Because when i = n-1, we are accessing dp[i+2] = dp[n+1]. so dp array size should be n+2 (0 to n+1).
        for(int i = n-1; i>=0; i--){
            int opt1 = nums[i] + dp[i+2];
            int opt2 = dp[i+1];
            dp[i] = max(opt1, opt2);
        }   
        return dp[0];
    }
    int rob(vector<int>& nums) {
        return solve(0, nums);
    }
};

//...........................................................
//DP with space optimization
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int solveSO(int i, vector<int>&nums){
        int n = nums.size();
        int prev = nums[n-1];
        int next = 0;
        int curr;

        for(int i = n-2; i>=0; i--){
            int opt1 = nums[i] + next;
            int opt2 = 0 + prev;
            curr = max(opt1, opt2);
            
            //shifting
            next = prev;
            prev = curr;
        }   
        return curr;
    }

    int rob(vector<int>& nums) {
        return solveSO(0, nums);
    }
};