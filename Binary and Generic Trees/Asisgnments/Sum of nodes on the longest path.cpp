//GFG - Sum of nodes on the longest path

class Solution
{
public:
    pair<int,int> height(Node* root){
        if(root == NULL) return {0,0};
        
        auto lh = height(root->left);
        auto rh = height(root->right);
        
        int sum = root->data;
        if(lh.first == rh.first){
            //height same - take the max sum (of either left or right)
            sum += lh.second > rh.second ? lh.second : rh.second;
        }
        //jiski height jayda, usika sum lenge
        else if(lh.first > rh.first){
            sum += lh.second;
        }
        else{
            sum += rh.second;
        }
        return {max(lh.first, rh.first)+1, sum};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        auto h = height(root);
        return h.second;
    }
};
