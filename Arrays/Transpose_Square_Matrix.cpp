#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) { 
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Display the transposed matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>>mat{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    transpose(mat);
    return 0;
}
