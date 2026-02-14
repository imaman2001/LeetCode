class Solution {
public:
    // int orangesRotting(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     queue<pair<pair<int,int>, int>>qq;
    //     int vis[n][m];
    //     int cntFresh = 0;

    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             if(grid[i][j] == 2){
    //                 qq.push({{i,j},0}); // here zero is the time
    //                 vis[i][j] = 2;
    //             }else{
    //                 vis[i][j] = 0;
    //             }

    //             if(grid[i][j] == 1) cntFresh++;
    //         }
    //     }

    //     int tm = 0;
    //     int drow[] = {-1, 0, +1, 0};
    //     int dcol[] = {0, +1, 0, -1};
    //     int cnt = 0;
    //     while(!qq.empty()){
    //         int r = qq.front().first.first;
    //         int c = qq.front().first.second;
    //         int t = qq.front().second;
    //         tm = max(t, tm);
    //         qq.pop();

    //         for(int i=0; i<4; i++){
    //             int nrow = r + drow[i];
    //             int ncol = c + dcol[i];
    //             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
    //                 qq.push({{nrow, ncol}, t+1});
    //                 vis[nrow][ncol] = 1;
    //                 cnt++;
    //             }
    //         }
    //     }

    //     if(cnt != cntFresh) return -1;

    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             if(vis[i][j] != 2 && grid[i][j] == 1){
    //                 return -1;
    //             }
    //         }
    //     }
    //     return tm;
    // }

    int orangesRotting(vector<vector<int>>& grid){
        if(grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        int days = 0;
        int total = 0;
        int cnt = 0;
        queue<pair<int,int>>rotten;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    total++;
                }
                if(grid[i][j] == 2){
                    rotten.push({i,j});
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!rotten.empty()){
            int k = rotten.size();

            cnt += k;

            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i]; 
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2;

                    rotten.push({nx, ny});
                }
                    
            }
            if (!rotten.empty()) days++;
        }
        return total == cnt ? days : -1;
    }
};