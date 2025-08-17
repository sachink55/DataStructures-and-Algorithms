//leetcode-437: Path Sum III 

class Solution {
public:
    int ans = 0;
    void pathFromOneRoot(TreeNode* root, long long sum){
        if(!root) return;
        if(root->val == sum){
            ++ans;
        }
        pathFromOneRoot(root->left, sum - root->val);
        pathFromOneRoot(root->right, sum - root->val);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            pathFromOneRoot(root, targetSum);

            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};