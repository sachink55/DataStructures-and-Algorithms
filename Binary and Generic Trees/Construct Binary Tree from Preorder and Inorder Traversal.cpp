//leetcode-105: Construct Binary Tree from Preorder and Inorder Traversal

 class Solution {
    public:
        void createValueToIndexMap(vector<int>inorder, int size, map<int,int>&valueToIndexMap){
            for(int i=0; i<size; i++){
                int element = inorder[i];
                valueToIndexMap[element] = i;
            }
        }
        TreeNode* constructTreeFromPreAndInorder(vector<int>preorder, vector<int>inorder, int &preIndex,int inorderStart, int inorderEnd, int size,map<int,int>&valueToIndexMap){
            //base case
            if(preIndex >= size || inorderStart > inorderEnd){
                return NULL;
            }
    
            //1 case solve karo
            int element = preorder[preIndex];
            preIndex++;
            TreeNode* root = new TreeNode(element);
            //find index/position of root inorder me
            int position = valueToIndexMap[element];
    
            //baki recursion sambhal lega
            root->left = constructTreeFromPreAndInorder(preorder, inorder, preIndex, inorderStart, position-1, size, valueToIndexMap);
            root->right = constructTreeFromPreAndInorder(preorder, inorder, preIndex, position+1, inorderEnd, size, valueToIndexMap);
    
            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int preIndex = 0;
            int size = preorder.size();
            int inorderStart = 0;
            int inorderEnd = size-1;
           
            map<int,int>valueToIndexMap;
            createValueToIndexMap(inorder,size, valueToIndexMap);
    
            TreeNode* tree = constructTreeFromPreAndInorder(preorder, inorder, preIndex, inorderStart, inorderEnd, size, valueToIndexMap);
            return tree;
        }
    };