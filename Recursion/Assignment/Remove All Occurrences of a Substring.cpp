//leetcode - 1910 : Remove All Occurrences of a Substring

//Approach - 1 : Aam Zindagi (Recursion)
//T.C : O(n^2)  [since s.find() & s.erase() both takes O(n) and in worst case no. of recursive calls n/m  -> O(n)×O(n/m) = O(n^2/m)] 
//S.C : O(n)    [O(n/m)]

class Solution {
public:
    void remove(string &s, string part){
        //base case 
        if(s.find(part) == string::npos){
            return;
        }

        //ek case khud se
        if(s.find(part) != string::npos){
            s.erase(s.find(part), part.length());
        }
        //recursion
        remove(s, part);
    }

    string removeOccurrences(string s, string part) {

        remove(s, part);
        return s;
    }
};

//...........................................................................................
//Approach - 2 : Mentos Zindagi (2 lines while loop)
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    
    string removeOccurrences(string s, string part) {

        while(s.find(part) != string::npos){
            //part has been located  -- remove it & update string s
            s = s.erase(s.find(part), part.length());
        }
        return s;
    }
};