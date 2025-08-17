//leetcode-230: Kth Smallest Element in a BST

class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root == NULL){
            return -1;  
        }
        //LNR -- INORDER
        //L
        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1){
            return leftAns;
        }

        //N
        k--;
        if(k==0){
            return root->val;
        }

        //R
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};


//Approach-2:

class Solution {
public:
    int ans, count = 0;

    void inorder(TreeNode* root, int k) {
        if(!root) return;

        inorder(root->left, k);
        
        count++;
        if(count == k) {
            ans = root->val;
            return;  // found kth smallest
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
