    //Approach - 1:
    //TC -- O(N) SC -- O(N)

    vector<Node*>inorder;
    Node * findPredecessor(Node *root, Node *p)
    {
        if(!root) return NULL;

        findPredecessor(root->left, p);
        inorder.push_back(root);
        findPredecessor(root->right, p);

        //linear search, we can use binary search too 
        for(int i=0; i<inorder.size(): i++){
            if(p == inorder[i])
                return inorder[i-1];
        }
        return NULL;
    }

    //Approach - 2 : 
    //TC -- O(h), SC-- O(1)  h- height
    //if root data is less than x then root might be the pred, store it and serach in right. bcz we have to find node just less than p.
    //else less than p nodes are in left of the root. 

    Node* findPredecessor(Node* root, Node* p) {
            Node* pred = 0;
            while(root){
                if(root->data < p->data){
                    pred = root;
                    root = root->right;
                }
                else{
                    root = root->left;
                }
            }
            return pred;
    }