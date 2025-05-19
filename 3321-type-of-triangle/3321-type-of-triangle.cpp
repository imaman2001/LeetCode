class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        if(nums[0] == nums[1] && nums[1] == nums[2]){
            return "equilateral";
        } else if(nums[0] != nums[1] && nums[1] != nums[2] &&
                 nums[0] != nums[2] && (nums[0] + nums[1] > nums[2]) &&
                 (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1])){
            return "scalene";
        } else if((nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2]) && 
                    (nums[0] + nums[1] > nums[2]) &&
                    (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1])){
            return "isosceles";
        }
        return "none";
    }
};