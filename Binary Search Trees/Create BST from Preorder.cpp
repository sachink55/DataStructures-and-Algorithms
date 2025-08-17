//leetcode-1008: Construct Binary Search Tree from Preorder Traversal

class Solution {
public:
    TreeNode* buildBST(vector<int>&preorder, int &i, int min, int max){
        //base case
        if(i >= preorder.size()) return NULL;

        TreeNode* root = NULL;
        if(preorder[i] > min && preorder[i] < max){
            root =  new TreeNode(preorder[i++]);
            root->left = buildBST(preorder, i, min, root->val); 
            root->right = buildBST(preorder, i, root->val, max);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN; int max = INT_MAX;
        int i = 0;
        return buildBST(preorder, i, min, max);
    }
};