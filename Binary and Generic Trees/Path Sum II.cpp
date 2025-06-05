//leetcode-113: Path Sum II

class Solution {
    public:
        void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum) {
            //base case
            if(root == NULL) {
                return;
            }
            //1 case solve krna hai
            sum += root->val;
            temp.push_back(root->val);
    
            //extra case
            if(root->left == NULL && root->right == NULL) {
                //verify
                if(sum == targetSum) {
                    //store temp path in final ans array
                    ans.push_back(temp);
                }
                else {
                    return;
                }
            }
    
            //baaki recursion sambhal lega
            solve(root->left, targetSum, ans, temp, sum);
            solve(root->right, targetSum, ans, temp, sum);
        }
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> ans;
            vector<int> temp;
            int sum = 0;
            solve(root, targetSum, ans, temp, sum);
            return ans;
        }
};