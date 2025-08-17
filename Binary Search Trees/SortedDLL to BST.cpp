
Node* convertDLLtoBST(Node* head, int n){
    //base case
    if(head == NULL || n<=0) return NULL;

    Node* leftSubtree = convertDLLtoBST(head, n/2);

    Node* root = head;
    root->left = leftSubtree;
    //head updates to the next node in the DLL
    head = head->right; 

    root->right = convertDLLtoBST(head, n - n/2 - 1);

    return root;
}