class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<int>>& image, vector<vector<bool>>& vis ,int newColor, int oldColor ){
        vis[row][col] = true;
        image[row][col] = newColor;

        // up 
        // (check not overflow  && traverse only not already visited  && check is up value == oldColor of center(sr.sc) )
        if(row-1 >= 0 && !vis[row-1][col] && image[row-1][col] == oldColor){
            dfs(row-1, col, n, m, image, vis, newColor, oldColor);
        }
        
        // down
        if(row+1 < n && !vis[row+1][col] && image[row+1][col] == oldColor){
            dfs(row+1, col, n, m, image, vis, newColor, oldColor);
        }

        // left
        if(col-1 >= 0 && !vis[row][col-1] && image[row][col-1] == oldColor){
            dfs(row, col-1, n, m, image, vis, newColor, oldColor);
        }

        // right
        if(col+1 < m && !vis[row][col+1] && image[row][col+1] == oldColor){
            dfs(row, col+1, n, m, image, vis, newColor, oldColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();   // rows
        int m = image[0].size();   // col

        vector<vector<bool>> vis(n, vector<bool>(m, false));    // in each row's , no. of m columns are present

        dfs(sr, sc, n, m, image, vis, newColor, image[sr][sc]);

        return image;
    }
};