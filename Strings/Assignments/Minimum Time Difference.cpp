//leetcode-539: Minimum Time Difference

class Solution {
public:
    int convertToMin(string&time){
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));
        return 60*hh + mm;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;
        for(auto time : timePoints){
            mins.push_back(convertToMin(time));
        }

        sort(mins.begin(), mins.end());

        int ans = INT_MAX; //min diff
        for(int i=0; i<mins.size()-1; i++){
            ans = min(ans, mins[i+1]-mins[i]);
        }

        //last diff - time is circular.
        int lastDiff = mins[0] + 1440 - mins[mins.size()-1];
        ans = min(ans, lastDiff);

        return ans;
    }
};