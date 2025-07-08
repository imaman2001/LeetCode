class Solution {
    int BS(vector<vector<int>>& events, int start){
        int l = 0, r = events.size() - 1;
        int ans = -1;

        while(l<=r){
            int mid = l + (r - l) / 2;
            if(events[mid][1] < start){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        // min heap based on  ending events
        sort(events.begin() , events.end() , [](const vector<int>& a , const vector<int>& b){
            return a[1] < b[1];
        });
        
        int n = events.size();  // based on rows
        vector<vector<int>> dp(n+1 , vector<int>(k+1, 0));
        
        for(int i=1; i<=n; i++){
            int prev = BS(events , events[i-1][0]);
            
            for(int j=1l; j<=k; j++){
                dp[i][j] = max(dp[i-1][j] , dp[prev+1][j-1] + events[i-1][2]);
            }
        }
        return dp[n][k];
    }
};