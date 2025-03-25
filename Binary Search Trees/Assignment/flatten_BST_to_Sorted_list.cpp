//Flatten BST to sorted list - gfg

//Approach-1 (Brute force)
//T.C : O(n + n * n) = O(n^2)
//S.C : O(n)

void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node* insertIntoBST(Node* root, int data) {
    if (!root) {
        return new Node(data); // Create a new node if the current position is null
    }
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data); // Go left if the data is smaller
    } else {
        root->right = insertIntoBST(root->right, data); // Go right if the data is larger
    }
    return root;
}

Node* flattenBST(Node* root) {
    vector<int> arr;
    inorder(root, arr);

    Node* newRoot = NULL;
    for (int data : arr) {
        newRoot = insertIntoBST(newRoot, data);
    }
    return newRoot;
}


//........................................................
//Approach-2 (Better store nodes in arr and create sorted list)
//T.C : O(n)
//S.C : O(n)

class Solution
{
public:

    void inorder(Node* root, vector<Node*>&arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }

    Node *flattenBST(Node *root)
    {
        vector<Node*>arr;
        inorder(root, arr);
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            arr[i]->left = NULL;
            if(i<n-1)
                arr[i]->right = arr[i+1];
        }
        //new root will be at the first element
        return arr[0];
    }
};

//....................................................
//Approach-3 : (flatten inorder-wise on the go)
//T.C : O(n)
//S.C : O(h)

class Solution
{
public:
    
    void inorder(Node* root, Node* &prev){
        if(!root) return;
        inorder(root->left,prev);
        
        prev->left = NULL;
        prev->right = root;
        prev = root;
        
        inorder(root->right,prev);
    }

    Node *flattenBST(Node *root)
    {
       Node* dummy = new Node(-1);
       Node* prev = dummy;
       inorder(root, prev);
       
       //last node
       prev->left = prev->right = NULL;
       
       root = dummy->right;
       return root;
    }
};