//Approach-1 : Bit Manipulation
//T.C : O(2^n * n)
//S.C : O(1)

#include<bits/stdc++.h>
using namespace std;

vector<string> AllPossibleStrings(string s) {
    int n = s.length();
    vector<string>ans;

    for(int i=0; i < (1<<n) ; ++i){             // 1<<n = 2^n
        string sub = "";
        for(int j=0; j<n; ++j){
            //check if ith bit is set or not
            if(n & (1<<j)){
                sub += s[j];
            }
        }
        ans.push_back(sub);
    }
    return ans;
}

int main(){
    string s = "abc";

    vector<string>ans = AllPossibleStrings(s);
    cout<<"All possible subsequences are : ";
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}

//Approach-2 : Recursion
//T.C : O(2^n)
//S.C : O(n)

void findSubsequences(string s, string output, int i){
    //base case
    if(i >= s.length()){
        //subsequnces output string me build ho chuka hai
        cout << output << endl;
        return;
    }

    char ch = s[i];

    //include
    output.push_back(ch);
    findSubsequences(s, output, i+1);

    //exclude
    output.pop_back();
    findSubsequences(s, output, i+1);
}