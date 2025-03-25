//leetcode-733 : Flood Fill

//Approach - DFS
class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int startColor, int newColor){
        if(x<0 || x >= image.size() || y<0 || y >= image[0].size() || image[x][y] != startColor){
            return;
        }
        //change the color of current pixel
        image[x][y] = newColor;
        
        //perform DFS on all adjacent pixels
        dfs(image, x+1, y, startColor, newColor);  //top
        dfs(image, x-1, y, startColor, newColor);  //down
        dfs(image, x, y-1, startColor, newColor);  //left
        dfs(image, x, y+1, startColor, newColor);  //right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];

        if(startColor == color) return image;

        dfs(image, sr, sc, startColor, color);
        return image;
    }
};