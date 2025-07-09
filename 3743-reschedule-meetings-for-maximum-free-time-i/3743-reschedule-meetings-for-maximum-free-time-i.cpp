class Solution {
public:
    // Need Dry Run
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int ans = 0;
        vector<int> sum(n+1, 0);
        
        for(int i=0; i<n; i++){
            sum[i+1] = sum[i] + (endTime[i] - startTime[i]);
        }

        for(int i=k-1; i<n; i++){
            int r;
            if(i == n - 1){
                r = eventTime;
            } else {
                r = startTime[i+1];
            }

            int l;
            if(i == k-1){
                l = 0;
            } else {
                l = endTime[i-k];
            }

            int freeT = r - l - (sum[i+1] - sum[i-k+1]);
            ans = max(ans , freeT);
        }
        return ans;
    }
};