class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> dp(n+1, -1);

        dp[0] = 0;
        dp[1] = 1;

        if(dp[n] != -1){
            return dp[n];
        }

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n];
    }
};