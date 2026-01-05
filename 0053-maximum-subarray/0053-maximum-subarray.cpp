class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Brute Force Approach
        // int max = INT_MIN;
        // int n = nums.size();

        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         int sum = 0;
        //         for(int k=i; k<=j; k++){
        //             sum += nums[k];
        //         }
        //         if(max > sum){
        //             max = max;
        //         } else {
        //             max = sum;
        //         }
        //     }
        // }
        // return max;


        //................ Optiomal solution
        int sum = 0;
        int maxi = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];

            if(sum > maxi){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }

        return maxi;
    }
};