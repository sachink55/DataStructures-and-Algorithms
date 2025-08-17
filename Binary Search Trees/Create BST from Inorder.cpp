//Create BST from Inorder

class Solution {
public:
    Node* buildBST(vector<int>& inorder, int s, int e) {
        if(s > e) return NULL;

        int mid = (s + e) / 2;   // middle element
        TreeNode* root = new Node(inorder[mid]);

        root->left = buildBST(inorder, s, mid - 1);   
        root->right = buildBST(inorder, mid + 1, e); 

        return root;
    }

    Node* sortedArrayToBST(vector<int>& inorder) {
        return buildBST(inorder, 0, inorder.size() - 1);
    }
};
