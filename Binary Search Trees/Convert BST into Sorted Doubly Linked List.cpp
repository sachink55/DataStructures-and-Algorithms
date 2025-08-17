//

//left - prev 
//right - next
void convertBSTtoDLL(Node* root, Node* head){
    if(!root) return NULL;

    //RNL
    convertBSTtoDLL(root->right, head);
    
    root->right = head;
    if(head) head->left = root; 
    head = root;

    convertBSTtoDLL(root->left, head);
}