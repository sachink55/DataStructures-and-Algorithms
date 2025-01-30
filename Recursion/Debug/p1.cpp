#include<bits/stdc++.h>
using namespace std;


bool isPowerOfFour(int n) {
    if(n<=1){
        return false;
    }
    if(n%4!=0){
        return false;
    }
       
    return isPowerOfFour(n/4);
}

int main(){
    int ans = isPowerOfFour(16);
    cout << "isPowerOfFour : " << ans;
    return 0;
}