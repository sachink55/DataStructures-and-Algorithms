//leetcode - 2391 : Minimum Amount of Time to Collect Garbage

//Approach-1:
//TC: O(n*k)
//SC: O(1)

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP=0, pickM=0, pickG=0;
        int travelP=0, travelM=0, travelG=0;
        int lastP=0, lastM=0, lastG=0;

        //calculate PickTime
        for(int i=0; i<garbage.size(); i++){
            string curr = garbage[i];
            for(int j=0; j<curr.size(); j++){
                if(curr[j] == 'P'){
                    pickP++;
                    lastP = i;
                }
                else if(curr[j] == 'M'){
                    pickM++;
                    lastM = i;
                }
                else if(curr[j] == 'G'){
                    pickG++;
                    lastG = i;
                }
            }
        }

        //calculate travel time
        for(int i=0; i<lastP; i++){
            travelP += travel[i];
        }
        for(int i=0; i<lastM; i++){
            travelM += travel[i];
        }
        for(int i=0; i<lastG; i++){
            travelG += travel[i];
        }

        int ans = (pickP + travelP) + (pickM + travelM) + (pickG + travelG);
        return ans;
    }
};


//Approach-2: 
//TC: O(n*k) n-length of garbage array   k- max length of garbage
//SC: O(1)

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int M = 0, P = 0, G = 0;
        int ans = garbage[0].size();

        for (int i = garbage.size() - 1; i > 0; i--) {
            for (char ch : garbage[i]) {
                if (ch == 'M') {
                    M = 1;
                } else if (ch == 'P') {
                    P = 1;
                } else {
                    G = 1;
                }
            }
            ans += travel[i - 1] * (M + P + G) + garbage[i].size();
        }

        return ans;
    }
};