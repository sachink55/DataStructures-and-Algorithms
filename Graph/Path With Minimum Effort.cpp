//leetcode - 1631 : Path With Minimum Effort
//Approach - Dijkstra's Algorithm

class Solution {
public:

    bool isSafe(int newX, int newY, int row, int col,vector<vector<int> >& diff, int currX, int currY ) {
        if(newX >=0 && newY >=0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY]) {
            return true;
        }
        else {
            return false;
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int, pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > mini;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int> > diff(row, vector<int>(col, INT_MAX));
        int destX = row-1;
        int destY = col-1;
        //initial state
        //set src ka distance 0
        diff[0][0] = 0;
        //min heap me entry for src push krdo
        mini.push({0,{0,0}});

        while(!mini.empty()) {
            auto topPair = mini.top();
            mini.pop();
            int currDiff = topPair.first;
            pair<int,int>  currNodeIndexPair = topPair.second;
            int currX = currNodeIndexPair.first;
            int currY = currNodeIndexPair.second;
        
            //now we can travel to all nbr i.e. top, down, left, right
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(isSafe(newX, newY,row,col,diff,currX, currY)) {
                    int maxDiff = max(currDiff, abs(heights[currX][currY]-heights[newX][newY]));
                    //check can we update diff array
                    diff[newX][newY] = min(diff[newX][newY], maxDiff);
                    
                    //entry create karo min Heap me
                    if(newX != destX || newY != destY) {
                        mini.push({diff[newX][newY], {newX, newY}});
                    }
                }
            }

        }
        return diff[destX][destY];
    }
};


// Same approach 
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        diff[0][0] = 0;
        pq.push({0, {0, 0}});
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto [currDiff, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;
            
            if (x == row - 1 && y == col - 1) return currDiff; // Early exit

            for (auto [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newY >= 0 && newX < row && newY < col) {
                    int maxDiff = max(currDiff, abs(heights[x][y] - heights[newX][newY]));
                    if (maxDiff < diff[newX][newY]) {
                        diff[newX][newY] = maxDiff;
                        pq.push({maxDiff, {newX, newY}});
                    }
                }
            }
        }
        return 0; 
    }
};
