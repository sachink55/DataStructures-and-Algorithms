//leetcode -938 : Range sum of BST
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int ans = 0;

        if (root->val >= low && root->val <= high) { // Within the range hai
            ans = root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else if (root->val < low) { // go right
            ans = rangeSumBST(root->right, low, high);
        } 
        else {
            // go left
            ans = rangeSumBST(root->left, low, high);
        }
        return ans;
    }
};