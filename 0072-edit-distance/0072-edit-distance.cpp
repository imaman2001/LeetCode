class Solution {
public:
    int minDistance(string word1, string word2) {   // TC :- O(n*m)
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

        for(int i=0; i<n+1; i++){   // initilize all rows with i
            dp[i][0] = i;
        }

        for(int j=0; j<m+1; j++){   // initilize all the columns with j
            dp[0][j] = j;
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = 1 + min(min(dp[i-1][j] , dp[i][j-1]), dp[i-1][j-1]); // delete, insert ,replace
                }
            }
        }
        return dp[n][m];
    }
};