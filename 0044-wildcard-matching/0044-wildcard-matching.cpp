class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // storage + meaning
        vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , false));

        // initilize
        dp[0][0] = true;  // if text and patter string is empty --> match --> true

        for(int j=1; j<m+1; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }else {
                dp[0][j] = false;
            }
        }

        // bottom - up
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};