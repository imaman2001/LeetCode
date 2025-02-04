class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0] ;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }else{
                sum = nums[i];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};