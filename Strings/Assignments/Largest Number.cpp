//leetcode-179: Largest Number

class Solution {
public:
    //Custom Comprator
    static bool mycomp(string &a, string &b){
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2;
    }

    //if a = 30, b = 3 => t1=303, t2 = 330. returns false -> so b needs to be put first
    //if a = 9 , b = 5 => t1=95, t2=59. returns true -> so a needs to be put first.
    
    string largestNumber(vector<int>& nums) {
        //first store all numbers in string format
        vector<string>snums;
        for(auto n : nums){
            snums.push_back(to_string(n));
        }

        sort(snums.begin(), snums.end(), mycomp);
        //edge case
        if(snums[0] == "0") return "0";

        string ans = "";
        for(auto s : snums){
            ans += s;
        }

        return ans;
    }
};