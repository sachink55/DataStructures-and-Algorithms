//leetcode - 415 : Add Strings

//Approach - 1 : Brute Force (digit by digit addition)
//T.C : O(n)
//S.C : O(n) 

class Solution {
public:

    string addStrings(string num1, string num2) {

        string ans;
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0)
                carry += num1[i--] - '0';
            if (j >= 0)
                carry += num2[j--] - '0';
            ans += carry % 10 + '0';
            carry /= 10;
        }

        ranges::reverse(ans);
        return ans;
    }
};

//...........................................................................................................
//Approach - 2 : Using Recursion
//T.C : O(n)  where n = max (num1.length(), num2.length())
//S.C : O(n)

class Solution {
public:
    string addStr(string num1, int p1, string num2, int p2, int carry=0){
        //base case
        if(p1<0 && p2<0){
            if(carry !=0 ){
                return string(1, carry+'0');
            }
            return "";
        }

        //ek case mai solve karunga
        int n1 = (p1 >=0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >=0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum/10;

        string ans = "";
        ans.push_back(digit + '0');

        //recursion
        ans += addStr(num1, p1-1, num2, p2-1, carry);
        return ans;
    }

    string addStrings(string num1, string num2) {
        int p1 = num1.length()-1;
        int p2 = num2.length()-1;

        string ans = addStr(num1, p1, num2, p2);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//Same above approach but OPTIMIZED. Since strings size can be order of 10^4 (constraint given) and in above approach we are copying the string that will take time and space doing that. Toh pass by reference karnege.

//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    void addStr(string &num1, int p1, string &num2, int p2, int carry, string &ans){
        //base case
        if(p1<0 && p2<0){
            if(carry !=0 ){
                ans.push_back(carry+'0');
            }
            return;
        }

        //ek case mai solve karunga
        int n1 = (p1 >=0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >=0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum/10;

        ans.push_back(digit + '0');

        //recursion
        addStr(num1, p1-1, num2, p2-1, carry, ans);
    }

    string addStrings(string num1, string num2) {

        string ans = "";
        addStr(num1, num1.length()-1, num2, num2.length()-1,0,ans);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
