
class Solution {
public:
    int height(TreeNode* root) {
        //Base Case
        if(root == NULL){
            return  0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = height(root->left) + height(root->right);
        int diameter=  max(opt1, max(opt2, opt3));

        return diameter;
    }
};

//Approach - 2 : Better Way
class Solution {
public:
    int D = 0;
    int height(TreeNode* root) {
        //Base Case
        if(root == NULL){
            return  0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        int currD = lh + rh;
        D = max(D, currD);
        return max(lh, rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return D;
    }
};