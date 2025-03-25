// interviewBit-394 : Valid BST from preorder
//T.C : O(n)
//S.C: O(1)

void build(int &i, int min, int max, vector<int>&A){
        if(i >= A.size()){
            return ;
        }
        
        if(A[i] > min && A[i] < max){
            int rootData = A[i++];
            build(i, min, rootData, A);
            build(i, rootData, max, A);
        }
    }
int Solution::solve(vector<int> &A) {
    int i=0;
    int min = INT_MIN;
    int max = INT_MAX;
    build(i, min, max, A) ;
    return i==A.size();
}
