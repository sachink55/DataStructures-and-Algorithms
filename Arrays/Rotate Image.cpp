//leetcode-48 : Rotate Image 

//Appraoch : 1. Transpose the matrix 2. Then reverse each row

void rotate(vector<vector<int>&mat){
    int n = mat.size();
    //transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    //reverse each row
    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}