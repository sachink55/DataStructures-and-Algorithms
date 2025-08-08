//Binary Tree Views - 

//1. Left View 
void leftViewTree(Node* root, int level, vector<int>& leftView) {
    if (root == NULL) return;

    // If this is the first node of its level
    if (level == result.size()) {
        leftView.push_back(root->data);
    }

    // for left and right subtrees
    leftViewTree(root->left, level + 1, leftView);
    leftViewTree(root->right, level + 1, leftView);
}

//2. Right View 
void rightViewTree(Node* root, int level, vector<int>& rightView) {
    if (root == NULL) return;

    // If this is the first node of its level
    if (level == rightView.size()) {
        rightView.push_back(root->data);
    }

    // for right and left subtrees - just change the order
    rightViewTree(root->right, level + 1, rightView);
    rightViewTree(root->left, level + 1, rightView);
}


//3. Top View 
void topViewTree(Node* root) {
    map<int, int>mp;
    queue<pair<Node*, int>> q; // for level or horizontal distance
    q.push({root, 0});

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second; // horizontal distance

        //if there is no entry for hd in map, add it
        if (mp.find(hd) == mp.end()) {
            mp[hd] = frontNode->data;
        }

        //child ko insert karo
        if (frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }
        if (frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    cout << "Top View: ";
    for (auto it : mp) {
        cout << it.second << " ";
    }
}


//4. Bottom View
void bottomViewTree(Node* root) {
    map<int, int>mp;
    queue<pair<Node*, int>> q; // for level or horizontal distance
    q.push({root, 0});

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second; // horizontal distance

        //always update the bottom view with the latest node at this hd
        mp[hd] = frontNode->data;

        //child ko insert karo
        if (frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }
        if (frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    cout << "Bottom View: ";
    for (auto it : mp) {
        cout << it.second << " ";
    }
}
   