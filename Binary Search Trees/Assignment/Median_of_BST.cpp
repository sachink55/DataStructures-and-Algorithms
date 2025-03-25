//Median of BST - gfg

//Approach-1
//T.C : O(n)
//S.C : O(n)

void inorder(struct Node* root, vector<int>&arr){
    if(!root)
        return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
float findMedian(struct Node *root)
{
     vector<int>arr;
     inorder(root,arr);
     float ans;
     int n = arr.size();
     
     if(n%2 == 0){
          ans = (float)(arr[(n/2)-1] + arr[n/2])/2.0;
          return ans;
       
     }
     ans = (float) arr[n/2];
     return ans;
}

//----------------------------------------------------------------------
//Approach-2(Using Morris Traversal)
//T.C : O(n)
//S.C : O(1)

int findNodeCount(Node* root) {
        int count = 0;
        Node* curr = root;
        while(curr){
            //left Node is NULL then visit it, and go right
            if(curr->left == NULL){
                count++;
                curr = curr->right;
            }
            //left Node NULL nahi hai
            else{
                //find inorder predecessor
                Node* pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }
                //if pred right Node is NULL, then go left after establishing connection
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    //left is already visited, go right after visitng curr and remove connection
                    pred->right = NULL;
                    count++;
                    curr = curr->right;
                }
            }
        }
        return count;
}

float getMedian(Node* root, int n) {
        int i = 0;
        int odd1 = (n+1)/2, odd1Val = -1;
        int even1 = n/2 , even1Val = -1;
        int even2 = n/2 + 1, even2Val = -1;
        Node* curr = root;
        while(curr){
            //left Node is NULL then visit it, and go right
            if(curr->left == NULL){
                i++;
                if(i == odd1) odd1Val = curr->data;
                if(i == even1) even1Val = curr->data;
                if(i == even2) even2Val = curr->data; 
                
                curr = curr->right;
            }
            //left Node NULL nahi hai
            else{
                //find inorder predecessor
                Node* pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }
                //if pred right Node is NULL, then go left after establishing connection
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    //left is already visited, go right after visitng curr and remove connection
                    pred->right = NULL;
                    i++;
                    if(i == odd1) odd1Val = curr->data;
                    if(i == even1) even1Val = curr->data;
                    if(i == even2) even2Val = curr->data;
                    curr = curr->right;
                }
            }
        }
    float median = 0;
    if(n%2 == 0)
        median = (even1Val + even2Val) / 2.0;
    else
        median = odd1Val;
        
    return median;
}

float findMedian(struct Node *root)
{
     int n = findNodeCount(root);
     return getMedian(root, n);
}