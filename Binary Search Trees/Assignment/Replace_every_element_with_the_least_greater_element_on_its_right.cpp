//
//Approach-1 (using set)
//T.C : O(nlogn)
//S.C : O(n)

class Solution{
public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        set<int> s;
        vector<int> ans(n,-1);

         for(int i = n-1; i>=0; i--){
            s.insert(arr[i]);
            if(s.upper_bound(arr[i]) != s.end()){   //st.upper_bound(x) returns iterator to the element just greater than x
                ans[i] = *(s.upper_bound(arr[i]));
            }
        }
        return ans;
    }
};

//.........................................................
//Approach-2 (using binary search tree)
//T.C : 0(n * logn) worst case: O(n*n) = O(n^2)
//S.C : O(n)

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val):data(val), left(0), right(0) {};
};

class Solution{
    public:
    Node* insert(Node* root, int val, int &succ){
        if(!root) return new Node(val);
        
        if(val >= root->data){
            root->right = insert(root->right, val, succ);        
        }
        else{
            succ = root->data;
            root->left = insert(root->left, val, succ);
        }
    }
    
   vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(n, -1);
        Node* root = 0;
        
        for(int i= n-1; i>=0; --i){
            int succ = -1;
            root = insert(root, arr[i] ,succ);
            ans[i] = succ;
        }
        return ans;
   }
};