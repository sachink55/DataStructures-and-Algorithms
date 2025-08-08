//print left nodes before leaf nodes
//print leaf nodes
//print right nodes

void printLeftBoundary(Node* root) {
    if(!root || (!root->left && !root->right)) {
        return;
    }
    cout << root->data << " ";
    if(root->left) {
        printLeftBoundary(root->left);
    } else {
        printLeftBoundary(root->right);
    }
}

void printLeafNodes(Node* root) {
    if(!root) {
        return;
    }
    if(!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printRightBoundary(Node* root) {
    if(!root || (!root->left && !root->right)) {
        return;
    }
    if(root->right) {
        printRightBoundary(root->right);
    } else {
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node* root) {
    if(!root) {
        return;
    }
    
    cout << root->data << " "; // Print root node
    
    printLeftBoundary(root->left); // Print left boundary
    printLeafNodes(root->left);           // Print leaf nodes
    printLeafNodes(root->right);          // Print leaf nodes
    printRightBoundary(root->right); // Print right boundary
}