//leetcode - 300 : Longest Increasing Subsequence

//Approach - 1 : Using Recursion
//T.C : O(2^n)
//S.C : O(n)

class Solution {
public:
    // RECURSION
    int solveUsingRecursion(vector<int>& nums, int curr, int prev) {
        // base case
        if (curr >= nums.size())
            return 0;

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingRecursion(nums, curr + 1, curr);
        }
        int exclude = solveUsingRecursion(nums, curr + 1, prev);

        return max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int ans = solveUsingRecursion(nums, curr, prev);
        return ans;
    }
};

//................................................................................
//Approach - 2 : DP
//T.C : O(n^2)
//S.C : O(n^2)

//Memoization
class Solution {
public:
     int solveUsingMem(vector<int>& nums, int curr, int prev, vector<vector<int>>&dp) {
         // base case
         if (curr >= nums.size())
             return 0;

        //already exists
        if(dp[curr][prev+1] != -1)  //why prev+1 ?  (index shifting)
            return dp[curr][prev+1];

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingMem(nums, curr + 1, curr, dp);
        }
        int exclude = solveUsingMem(nums, curr + 1, prev, dp);

        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        int ans = solveUsingMem(nums, curr, prev, dp);
        return ans;
    }
};

//Tabulation
class Solution {
public:
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                int exclude = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return solveUsingTabulation(nums);
    }
};

//Space Optimisation
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    int solveUsingTabulationSO(vector<int>& nums) {
        int n = nums.size();
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + nextRow[curr + 1];
                }
                int exclude = nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            //shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int lengthOfLIS(vector<int>& nums){
        return solveUsingTabulationSO(nums);
    }
};

//..................................................................................
//Approach - 3 : Binary Search with DP (Optimal Approach)
//T.C : O(nlogn)
//S.C : O(n)

int solveUsingBS(vector<int>&nums){
    vector<int>ans;
    //initial state
    ans.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++){
        if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            //just bda number exist karta hai, use replace kardo
            int index  = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            //replace
            ans[index] = nums[i];
        }
        return ans.size();
    }
}