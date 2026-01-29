class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cover = n - 1;
        for(int i=n-1; i>=0; i--){
            // if its true it means nums[i] is capable to reach out to goal successfully
            if(i + nums[i] >= cover){
                cover = i;
            }
        }
        return cover == 0;

    }
};