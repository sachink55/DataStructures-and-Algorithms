//leetcode - 1691 : Maximum Height by Stacking cuboids

//Approach : DP Tabulation
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    bool check(vector<int>&curr, vector<int>&prev){
        //curr - Bada wala cuboid
        //prev - Chhota wala cuboid
        //Since cuboids is sorted and we are looping from n-1 index. To last me bda wala dabba hi hoga
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
            return true;
        }
        else
            return false;
    }
    
    int solve(vector<vector<int>>& cuboids){
        int n = cuboids.size();

        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev])){
                    int heightToAdd = cuboids[curr][2];
                    include = heightToAdd + nextRow[curr+1];
                }
                int exclude  = nextRow[prev+1];
                currRow[prev+1] = max(include, exclude);
            }
            //shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids);
    }
};