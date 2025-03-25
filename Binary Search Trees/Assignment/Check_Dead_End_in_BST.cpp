//Check whether a BST contains dead end - gfg

//Approach : Dead end should be a leaf node(x) and if x+1 and x-1 already exist i'm at dead end.
//T.C : O(n)
//S.C : O(n)

class Solution{
  public:
    void fun(Node* root, unordered_map<int, bool>&visited, bool &ans){
        if(!root) return;
        visited[root->data] = 1;
        if(!root->left && !root->right){
            int xp1 = root->data + 1; // x plus 1
            int xm1 = root->data - 1 == 0 ? root->data : root->data - 1; //x minus 1
            if(visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()){
                ans = true;
                return;
            }
        }
        fun(root->left, visited, ans);
        fun(root->right, visited, ans);
    }
    
    bool isDeadEnd(Node *root)
    {
       bool ans;
       unordered_map<int, bool>visited;
       fun(root, visited, ans);
       return ans;
    }
};