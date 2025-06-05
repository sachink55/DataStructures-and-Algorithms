//leetcode-106: Construct Binary Tree from Inorder and Postorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
       void createValueToIndexMap(vector<int>inorder, int size, map<int,int>&valueToIndexMap){
            for(int i=0; i<size; i++){
                int element = inorder[i];
                valueToIndexMap[element] = i;
            }
        }
        TreeNode* constructTreeFromPreAndInorder(vector<int>postorder, vector<int>inorder, int &postIndex,int inorderStart, int inorderEnd, int size,map<int,int>&valueToIndexMap){
            //base case
            if(postIndex < 0 || inorderStart > inorderEnd){
                return NULL;
            }
    
            //1 case solve karo
            int element = postorder[postIndex];
            postIndex--;
            TreeNode* root = new TreeNode(element);
            //find index/position of root inorder me
            int position = valueToIndexMap[element];
    
            //baki recursion sambhal lega
            //pahle right subtree construct hoga, postorder L R N hota hai.  and it's going from right to left
    
            root->right = constructTreeFromPreAndInorder(postorder, inorder, postIndex, position+1, inorderEnd, size, valueToIndexMap);
            root->left = constructTreeFromPreAndInorder(postorder, inorder, postIndex, inorderStart, position-1, size, valueToIndexMap);
           
    
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int size = postorder.size();
            int postIndex = size - 1;
            int inorderStart = 0;
            int inorderEnd = size-1;
           
            map<int,int>valueToIndexMap;
            createValueToIndexMap(inorder,size, valueToIndexMap);
    
            TreeNode* tree = constructTreeFromPreAndInorder(postorder, inorder, postIndex, inorderStart, inorderEnd, size, valueToIndexMap);
            return tree;
        }
    };