class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1 , suffix = 1;
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];   // left to right
            suffix *= nums[n-i-1]; // right to left

            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};