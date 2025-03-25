//leetcode-200 : Number of Islands

//Approach - DFS (Grid Based)
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i >= grid.size() || j<0 || j >= grid[0].size() || grid[i][j] != '1'){
            return;
        }

        grid[i][j] = '0';   //mark as visited
        dfs(grid, i-1, j);  //up
        dfs(grid, i+1, j);  //down
        dfs(grid, i, j+1);  //left
        dfs(grid, i, j-1);  //right
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
};


// Using BFS
class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& vis) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = true;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // Up, Down, Right, Left

        while (!q.empty()) {
            auto [currX, currY] = q.front(); q.pop();
            for (auto [dx, dy] : directions) {
                int newX = currX + dx, newY = currY + dy;
                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols && grid[newX][newY] == '1' && !vis[newX][newY]) {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    bfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
