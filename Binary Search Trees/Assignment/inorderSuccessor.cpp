
//Approach - 1 : TC -- O(N),  SC -- O(N)
//using an array to store inorder traversal and returning the next greater value than x
class Solution{
  public:
    vector<Node*>inorder;

    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(!root) return NULL;

        inOrderSuccessor(root->left, x);
        inorder.push_back(root);
        inOrderSuccessor(root->right, x);

        //linear search, we can use binary search too 
        for(int i=0; i<inorder.size(): i++){
            if(x == inorder[i] && i < inorder.size())
                return inorder[i+1];
        }
        return NULL;
    }
};

//Approach - 2 : TC -- O(h), SC-- O(1)  h- height
//if root data is greater than x then root might be the succ, store it and serach in left. bcz we have to find node just grater than x.
//else greater than x nodes are in right of the root.
class Solution{
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ = 0;
        while(root){
            if(root->data > x->data){
                succ = root;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return succ;
    }
};