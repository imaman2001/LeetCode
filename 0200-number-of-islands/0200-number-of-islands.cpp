class Solution {
private:
    // void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
    //     vis[row][col] = 1;
    //     queue<pair<int,int>>q;
    //     q.push({row,col});
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     while(!q.empty()){
    //         int r = q.front().first;
    //         int c = q.front().second;
    //         q.pop();

    //         // getting all the neighbours in all 8 directions
    //         for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
    //             for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
    //                 int nrow = deltaRow + r;
    //                 int ncol = deltaCol + c;

    //                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
    //                     q.push({nrow, ncol});
    //                     vis[nrow][ncol] = 1;
    //                 }
    //             }
    //         }
    //     }
    // }

    void dfs(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col] == '0') return;

        grid[row][col] = '0';

        dfs(row-1, col, grid);
        dfs(row+1, col, grid);
        dfs(row, col-1, grid);
        dfs(row, col+1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>vis(n, vector<int>(m, 0));

        int count = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == '1'){
                    dfs(row, col, grid);
                    count++;
                }
            }
        }
        return count;
    }
};