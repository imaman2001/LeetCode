class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int right = 0;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            right += nums[i];
        }

        int left = 0;
        for(int i=0; i<nums.size(); i++){
            right -= nums[i];
            ans.push_back(abs(left-right));
            left += nums[i];
        }
        return ans;
    }
};