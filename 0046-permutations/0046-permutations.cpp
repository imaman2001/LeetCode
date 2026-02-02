class Solution {
public:
    void bt(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& ans){
        int n = nums.size();
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i] == true) continue;
            used[i] = true;
            curr.push_back(nums[i]);

            bt(nums, curr, used, ans);

            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        vector<bool>used(nums.size(), false);
        vector<vector<int>> ans;
        bt(nums, curr, used, ans);
        return ans;
    }
};