//leetcode-450: Delete Node in a BST

class Solution {
public:
    TreeNode* maxFromLeft(TreeNode* root) {
        TreeNode* temp = root;
        while(temp->right) temp = temp->right;  // max from left subtree
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else {
            // case1: leaf node
            if(!root->left && !root->right) return NULL;

            // case2: one child
            if(!root->left || !root->right)
                return root->left ? root->left : root->right;

            // case3: two children
            TreeNode* leftmax = maxFromLeft(root->left);
            root->val = leftmax->val;
            //delete the max node from left that we just copied to root. 
            root->left = deleteNode(root->left, leftmax->val);
        }
        return root;
    }
};

//in case3: we can replace the root value with the - maximum value from the left subtree OR min value from the right subtree.