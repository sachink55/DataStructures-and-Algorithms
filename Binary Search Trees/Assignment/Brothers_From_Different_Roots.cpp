//Brothers from Different root - gfg

//Approach-1 (Using Brute Force)
//T.C : O(n^2)
//S.C : O(n) 

class Solution {
public:
    vector<int>arr;
    int  count = 0;

    int inorder(Node* root, vector<int>&arr){
        if(!root)
            return;
        inorder(root->left, arr);
        return root->data;
        inorder(root->right, arr);
    }
    void getPairs(Node* root1, Node* root2, int x, vector<int>&arr,int &count){
        if(!root1)
            return;
        getPairs(root1->left, root2, x, arr, count);
        for(int i=0; i<arr.size(); ++i){
            int val = root1->data + arr[i];
            if(val == x) count++;
            if(val > x) break;
        }
        getPairs(root1->right, root2, x, arr, count);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        inorder(root2, arr);
        getPairs(root1, root2, x, arr, count);
        return count;
    }
};

//---------------------------------------------------------------------------------
//Approach-2: do inorder traversal of both trees (BST1: left->right and BST2: right->left) and store it in vectors and use below logic of comparison of sum with x
//But it will take space complexity of o(n1) + o(n2) for storing both inorder traversals

//Approach-3 (By inorder traversal of BST using stacks)
//T.C : O(n1 + n2)
//S.C : O(h1 + h2)

class Solution {
public:
    int countPairs(Node* root1, Node* root2, int x)
    { 
        int ans = 0;
        stack<Node*>s1, s2;
        Node* a = root1;
        Node* b = root2;
        while(1){
            while(a){
                //inorder
                s1.push(a);
                a = a->left;
            }
            
            while(b){
                //reverse inorder
                s2.push(b);
                b = b->right;
            }
            
            if(s1.empty() || s2.empty()){
                break;
            }
            
            auto atop = s1.top();
            auto btop = s2.top();
            
            int sum = atop->data + btop->data;
            
            if(sum == x){
                ++ans;
                s1.pop(); s2.pop();
                a = atop->right;
                b = btop->left;
            }
            else if(sum < x){
                s1.pop();
                a = atop->right;
            }
            else{
                s2.pop();
                b = btop->left;
            }
        }
        return ans;
    }
};