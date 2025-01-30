//Convert a Complete Binary Search Tree (BST) into a Heap

void storeInorder(Node* root, vector<int>&inorder){
    if(!root) return;
    
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

//postorder -- L R N
void replaceUsingPostorder(Node* root, vector<int>inorder, int &index){
    if(!root) return;

    replaceUsingPostorder(root->left, inorder, index);
    replaceUsingPostorder(root->right, inorder, index);

    root->data = inorder[index];
    index++;
}

Node* convertBstToHeap(Node* root){
    vector<int>inorder;
    storeInorder(root, inorder);

    //replace the node values with stored inorder values using postorder traversal
    int index = 0;
    replaceUsingPostorder(root, inorder, index);

    return root;
}