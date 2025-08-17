//leetcode-236: Lowest Common Ancestor of a Binary Tree

//TC: O(n)
//SC: O(h) h-height of the tree

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (!root || root == p || root == q)
                return root;
    
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
    
            if(leftAns == NULL && rightAns == NULL)
                return NULL;
            else if(leftAns != NULL && rightAns == NULL)
                return leftAns;
            else if(leftAns == NULL && rightAns != NULL)
                return rightAns;
            else 
                return root;
        }
    };
    