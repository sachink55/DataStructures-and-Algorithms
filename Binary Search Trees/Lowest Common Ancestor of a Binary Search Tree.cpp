//leetcdoe-235: Lowest Common Ancestor of a Binary Search Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL) return NULL;

        //case1: if both p and q are in left Subtree of root
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        //case2: if both p and q are in right Subtree of root
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        //case3: p is in left subtree and q is in right subtree
        //case4: q is in left subtree and p is in right subtree
        //in both case lowest common ancestor will be root itself
        
        return root;
    }
};