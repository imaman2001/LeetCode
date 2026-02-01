class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int val0 = nums[0];
        int val1 = 50;
        int val2 = 50;
        int n = nums.size();
        // find 2 smallest values from the array
        for(int i=1; i<n; i++){
            if(val1 > nums[i]){
                val2 = val1;
                val1 = nums[i];
            } else if(val2 > nums[i]){
                val2 = nums[i];
            }
        }
        return val0 + val1 + val2;
    }
};