class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return 1;
        }

        if(dp[n] != -1){    // if dp[n] is already visited
            return dp[n];
        }

        dp[n] = helper(n-1 , dp) + helper(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        return helper(n, dp);

        // // Tabulation DP method (bottom - top)
        // vector<int> dp(n+1, 0);
        // dp[0] = 1;
        // dp[1] = 1;

        // for(int i=2; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
    }
};