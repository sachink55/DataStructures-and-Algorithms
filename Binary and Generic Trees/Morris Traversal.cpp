// Inorder Traversal - O(n), SC-O(n)

// Morris Traversal - O(n), SC-O(1)

vector<int> morrisTraversal(Node* root){
    vector<int> ans;
    Node* curr = root;
    while(curr){
        //left node is null -> visit it and go right
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        //left node is not null -> find inorder predecessor
        else{
            Node* pred = curr->left;
            while(pred->right != curr && pred->right){
                pred = pred->right;
            }

            //if right child of predecessor is null, make current as right child and go left
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                //left is already visited, go right after visiting current and remove the link
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

