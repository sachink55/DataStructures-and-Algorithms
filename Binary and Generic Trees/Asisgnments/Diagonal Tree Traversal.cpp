//GFG- Diagonal Tree Traversal

//Approach-1: when going left increase d, when going right do nothing

void solve(Node* root, int d, map<int,vector<int>>&mp){
    if(!root) return;
    mp[d].push_back(root->data);
    solve(root->left, d+1, mp);
    solve(root->right, d, mp);
}
vector<int> diagonal(Node *root)
{
    vector<int>ans;
    if(root==NULL)return ans;
    map<int, vector<int>>mp;
    solve(root , 0 , mp);

    for(auto d : mp){
        for(auto val : d.second){
            ans.push_back(val);
        }
    }
    return ans;
}

//..........................................................................................................
 //Approach-2: Using queue (level order technique)
class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front(); q.pop();
            while(temp){
                ans.push_back(temp->data);
                if(temp->left){
                    //Bad me dekhenge 
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
        return ans;
    }
};
