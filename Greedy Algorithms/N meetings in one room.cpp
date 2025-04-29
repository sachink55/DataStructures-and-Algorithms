//gfg - N meetings in one room

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> time;
        
        for(int i=0; i<n; i++){
            time.push_back({end[i], start[i]});
        }
        
        //sorting based on end time
        sort(time.begin(), time.end());
        
        int prevEnd = -1;
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(prevEnd == -1 || time[i].second > prevEnd){
                count++;
                prevEnd = time[i].first;
            }
        }
        
        return count;
    }
};