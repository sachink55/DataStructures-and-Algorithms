#include<bits/stdc++.h>
using namespace std;

//T.C : O(n)
//S.C : O(n)

void solve(string s, char p, int i, int &ans){
        //base case
        if(i >= s.size()){
            return;
        }

        if(s[i] == p)  
            ans = i;
        //aage search karo    
        solve(s, p, i+1, ans);
}

int main(){
       
        string s;
        char ch;

        cout<<"Enter string : ";
        cin >> s;
        cout<<"Enter Char : ";
        cin >> ch;

        int ans = -1;
        solve(s, ch, 0, ans);

        if(ans!=-1)
            cout << "Last occurrence of " << ch << " : " << ans << endl;
        else
            cout << ch << " is not there in "<<s;

        return 0;
}

//we can use strrchr() also to get the last occurrence of the char