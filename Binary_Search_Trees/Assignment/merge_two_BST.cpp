//Merge two BST's

//Appraoch-1 (Brute force)
//T.C : O(m+n)
//S.C: O(m+n)

class Solution {
  public:
    void inorder(Node* root, vector<int>&arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> arr1;
        vector<int> arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        
        vector<int>ans;
        int i = 0, j = 0;
        // Merge the two sorted arrays
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                ans.push_back(arr1[i++]);
            } else {
                ans.push_back(arr2[j++]);
            }
        }

        // Add remaining elements from arr1
        while (i < arr1.size()) {
            ans.push_back(arr1[i++]);
        }

        // Add remaining elements from arr2
        while (j < arr2.size()) {
            ans.push_back(arr2[j++]);
        }

        return ans;
    }
};

//...............................................
//Approach-2 (by inorder traversal using stacks)
//T.C : O(n1 + n2)
//S.C : O(h1 + h2)

class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>ans;
        stack<Node*>sa,sb;
        Node* a = root1, *b = root2;
        
        while(a || b || !sa.empty() || !sb.empty()){
            while(a){
                sa.push(a);
                a = a->left;
            }
            
             while(b){
                sb.push(b);
                b = b->left;
            }
            
            if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)){
                auto atop = sa.top(); sa.pop();
                ans.push_back(atop->data);
                a = atop->right;
            }
            else{
                auto btop = sb.top(); sb.pop();
                ans.push_back(btop->data);
                b = btop->right;
            }
        }
        return ans;
    }
};