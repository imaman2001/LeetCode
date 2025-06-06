class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1, 0);
        //if 0 and 1 node the possible solution is 1 to arrange the elements
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};