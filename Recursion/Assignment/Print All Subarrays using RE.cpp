#include<bits/stdc++.h>
using namespace std;

//T.C : O(n^2)
//S.C : O(n)

void printSubarray(vector<int>arr, int size, int i){
    //base case
    if(i >= size){
        return;
    }

    //ek case khud se
    cout << "subarray starting from  " << arr[i] << " :"<<endl;
    int j = i;
    while(j <= size-1){
        for(int k  = i ; k <= j;  k++){
          cout << arr[k] << " ";
        }
        cout << endl;
        j++;
    }
    
    printSubarray(arr, size, i+1);
}

int main(){
    
    vector<int>arr{1,2,3,4,5};
    printSubarray(arr, arr.size(), 0);
    return 0;
}