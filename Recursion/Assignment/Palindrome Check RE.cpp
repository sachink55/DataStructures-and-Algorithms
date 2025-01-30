#include<bits/stdc++.h>
using namespace std;

//T.C : O(n)
//S.C : O(n)

bool isPalindrome(string &s, int start, int end){
    //base case
    if(start >= end){
        return true;
    }
        
    //one case solution
    if(s[start] != s[end]){
        return false;
    }

    return isPalindrome(s, start+1, end-1);
}

int main(){
    string s;
    cin >> s;
    
    bool ans = isPalindrome(s, 0, s.length()-1);
    cout << "isPalindrome : " << ans << endl;

    return 0;
}