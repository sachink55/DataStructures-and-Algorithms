//leetcode-994 : Rotting Oranges
//Approach - BFS

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), fresh = 0, time = 0;
        queue<pair<int, int>> q;
        
        // Push all initially rotten oranges into queue & count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        // Directions: up, right, down, left
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        // BFS to spread the rot
        while (!q.empty() && fresh) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : directions) {
                    int newX = x + dx, newY = y + dy;
                    if (newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh ? -1 : time;
    }
};


