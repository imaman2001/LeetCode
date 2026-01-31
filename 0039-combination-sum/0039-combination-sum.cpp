class Solution {
public:
    // int n;
    // vector<int>nums , path;
    // vector<vector<int>> ans;
    // void backtrack(int target , int start){
    //     if(target == 0){
    //         ans.push_back(path);
    //         return;
    //     }
    //     for(int i=start; i<n; i++){
    //         if(nums[i] > target) continue;  // if number is greater then skip the number
    //         path.push_back(nums[i]);
    //         backtrack(target - nums[i] , i);
    //         path.pop_back();
    //     }
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     nums = candidates;
    //     n = nums.size();
    //     backtrack(target , 0);
    //     return ans;
    // }


//....................................................................
    void findCombinationOfSum(int idx, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int target){
        //base case
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }

        if(candidates[idx] <= target){
            curr.push_back(candidates[idx]);
            findCombinationOfSum(idx, candidates, ans, curr, target-candidates[idx]);
            curr.pop_back();
        }
        findCombinationOfSum(idx+1, candidates, ans, curr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> curr;
        findCombinationOfSum(0, candidates, ans, curr, target);
        return ans;
    }
};