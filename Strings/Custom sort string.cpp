//leetcode-791: Custom Sort String


//Approch: Matlab thik hai, itna jaruri nahi hai

class Solution {
public:
    // custom comparator
    static string str;
    static bool compare(char char1, char char2) {

        // this will return true, if position of character1 in str string is
        // less than the position of character2 in str string

        // when true is returned, then char1 will be placed before char2 in
        // output string
        return (str.find(char1) < str.find(char2));
    }
    string customSortString(string order, string s) {

        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
string Solution::str;


//........................................................................................................
//Approach-1:
//TC: O(nlogn)
//SC: O(logn)

class Solution {
public:
    string customSortString(string order, string s) {
        //Define the custom comparator as lambda
        sort(s.begin(), s.end(), [&](char c1, char c2) { 
            return order.find(c1) < order.find(c2);
        });
        
        return s;
    }
};

//........................................................................................................
//Approch-2:
//TC: O(n)
//SC: O(n)

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>freq;

        for(auto ch : s){
            freq[ch]++;
        }

        string ans = "";
        for(auto ch : order){
            while(freq[ch]-- > 0){
                ans += ch;
            }
        }
        
        //for remaining char, which are not in order
        for(auto &[ch, count] : freq){
            while(count-- > 0){
                ans += ch;
            }
        }
        return ans;
    }
};

