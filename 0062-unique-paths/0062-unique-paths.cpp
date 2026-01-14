class Solution {
private: 
    int memo(int m, int n, int i, int j, vector<vector<int>>& dp){
        //Base case
        if(i == m && j == n) return 1;
        if(i > m || j > n) return 0;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        } else {
            return dp[i][j] = memo(m, n, i+1, j , dp) + memo(m, n, i, j+1, dp);
        }
    }
public:
    int uniquePaths(int m, int n) {
    // memoization
        vector<vector<int>> dp(m , vector<int>(n , -1));
        int i=0 , j=0;
        return memo(m-1, n-1, i, j, dp);
    }
};