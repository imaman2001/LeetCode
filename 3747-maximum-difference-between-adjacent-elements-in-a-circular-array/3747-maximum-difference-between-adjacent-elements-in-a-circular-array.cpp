class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
    
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            ans = max(ans , abs(nums[i+1] - nums[i]));
        }
        
        ans = max(ans , abs(nums[n-1] - nums[0]));
        
        return ans;
    }
};