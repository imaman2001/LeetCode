class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int maxStreak = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                counter++;
            } else{
                counter = 0;
            }
            maxStreak = max(counter , maxStreak);
        }
        return maxStreak;
    }
};