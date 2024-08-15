class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        for(int num : nums){
            totalOnes = totalOnes + num;
        }

        if(totalOnes == 0 || totalOnes == n) {
            return 0;
        }
        int currOnes = 0;

        for(int i=0; i<totalOnes; i++){
            currOnes += nums[i];
        }
        int maxOnes = currOnes;

        for(int i=0; i<n; i++){
            currOnes = currOnes - nums[i];
            currOnes = currOnes + nums[(i + totalOnes) % n];
            maxOnes = max(maxOnes , currOnes);
        }
        return totalOnes - maxOnes;
    }
};