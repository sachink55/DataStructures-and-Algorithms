//leetcode-134: Gas Station

//Approach-1: Greedy Approach
//TC: O(n)
//SC: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        //index from where we are starting the movement
        int start = 0;

        //har index ko check karna hai ki, wo answer hai ya nahi
        for(int i=0; i<gas.size(); i++){
            balance = balance + gas[i] - cost[i];

            if(balance < 0){
                deficit += abs(balance);
                start = i+1;
                balance = 0;
            }
        }
        if((balance - deficit) >= 0)
            return start;
        else
            return -1;
    }
};


//Approach-2: Brute Force Approach
//  TC: O(n^2)
//  SC: O(n)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int start = 0; start < n; start++) {
            int fuel = 0;
            int cnt = 0;
            int i = start;

            while (cnt < n) {
                fuel += gas[i] - cost[i];
                if (fuel < 0) {
                    break;
                }
                i = (i + 1) % n; // move to next station
                cnt++;
            }
            if (cnt == n) {
                return start;
            }
        }
        return -1;
    }
};