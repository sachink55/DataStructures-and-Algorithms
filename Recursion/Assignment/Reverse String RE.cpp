#include<bits/stdc++.h>
using namespace std;

//T.C : O(n)
//S.C : O(n)

void reverse(string &s, int start, int end){
    if(start >= end)   return;

    swap(s[start], s[end]);
    
    reverseString(s, start+1, end-1);
}

int main(){
    string s;
    cout <<"Enter string to reverse : ";
    cin >> s;
    reverse(s, 0, s.size()-1);
    cout << "reversed string : " << s << endl;
    return 0;
}