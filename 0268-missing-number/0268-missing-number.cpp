class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        if(nums[0] != 0) return 0; // check 0th index  is 0  or not

        if(nums[n-1] != n) return n;  // check last index n or not

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != i){          // check all indexes with their value is or not 
                return i;
            }
        }
        return 0;
    }
};