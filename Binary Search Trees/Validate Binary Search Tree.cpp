//leetcode-98: Validate Binary Search Tree

class Solution {
public:
    bool solve(TreeNode* root, long lb, long ub) {
        if (!root) return true;
        
        //lb -> Lower Bound  ub-> Upper Bound
        if (!(root->val > lb && root->val < ub)) return false;

        return solve(root->left, lb, root->val) && solve(root->right, root->val, ub);
    } 

    bool isValidBST(TreeNode* root) {
        bool ans =  solve(root, LONG_MIN, LONG_MAX);
        return ans;
    }
};