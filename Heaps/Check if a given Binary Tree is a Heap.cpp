//gfg - Check if a given Binary Tree is a Heap


//Approach -1
class Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Info {
    public:
        int maxi;
        bool isHeap;
        Info(int a, bool b){
            this->maxi = a;
            this->isHeap = b;
        }
};

Info checkMaxHeap(Node * root){
    //base case
    if(root==NULL){
        Info temp(INT_MIN, true);
        return temp;
    }

    if(!root->left && !root->right){
        Info temp(root->data, true);
        return temp;
    }

    Info leftAns = checkMaxHeap(root->left);
    Info rightAns = checkMaxHeap(root->right);

    if(root->data > leftAns.maxi && root->data > rightAns.maxi && leftAns.isHeap && rightAns.isHeap){
        Info ans;
        ans.maxi = root->data;
        ans.isHeap = true;
        return ans;
    }
    else{
        Info ans;
        ans.maxi = max(root->data, max(leftAns.maxi, rightAns.maxi));
        ans.isHeap = false;
        return ans;
    }
}

//Approach - 2

pair<bool, int> solve(Node* root) {
        //base case
        if(root == NULL) {
                pair<bool,int> p = make_pair(true, INT_MIN);
                return p;
        }

        if(root->left == NULL && root->right == NULL)
        {
                //leaf node
                pair<bool,int> p = make_pair(true, root->data);
                return p;
        }

        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);

        if(leftAns.first == true &&
          rightAns.first == true &&
          root->data > leftAns.second &&
          root->data > rightAns.second) {
                  pair<bool, int> p =  make_pair(true, root->data);
                  return p;
          }
         
          else {
                  pair<bool, int> p =  make_pair(false, root->data);
                  return p;
          }
}
