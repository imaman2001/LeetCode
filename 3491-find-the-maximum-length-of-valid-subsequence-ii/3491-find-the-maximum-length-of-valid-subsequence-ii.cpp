class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 2;
        for(int i=0; i<k; i++){
            vector<int>dp(k, 0);

            for(int j=0; j<n; j++){
                int mm = nums[j] % k;
                int pos = (i - mm + k) % k;

                dp[mm] = dp[pos] + 1;
            }

            for(int num : dp){
                result = max(result, num);
            }
        }
        return result;
    }
};