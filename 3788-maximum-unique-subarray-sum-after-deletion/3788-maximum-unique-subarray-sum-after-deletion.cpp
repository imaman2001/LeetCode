class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool neg = true;
        int maxVal = INT_MIN;

        for(int n : nums){
            if(n >= 0){
                neg = false;
            }
            if(n > maxVal){
                maxVal = n;
            }
        }

        if(neg) return maxVal;

        unordered_set<int> set(nums.begin(), nums.end());

        int sum = 0;
        for(int val : set){
            if(val > 0){
                sum += val;
            }
        }

        return sum;
    }
};