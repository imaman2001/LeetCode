class Solution {
public:
    void findSubSet(int idx, vector<int>& piece, vector<int>& nums, set<vector<int>>& st){
        //base case
        if(idx == nums.size()){
            st.insert(piece);
            return;
        }

        piece.push_back(nums[idx]);
        findSubSet(idx+1, piece, nums, st);

        // if not included , backtrack to explore other choice
        piece.pop_back();
        findSubSet(idx+1, piece, nums, st);
    }

    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     set<vector<int>> st;
    //     vector<int>piece;
    //     sort(nums.begin(), nums.end());

    //     findSubSet(0, piece, nums, st);

    //     // convert set into 2D-vector
    //     vector<vector<int>> ans(st.begin() st.end());

    //     return ans;
    // }

    void FSS(int st, vector<int>& nums, vector<int>& curr, vector<vector<int>>& result){
        result.push_back(curr);

        for(int i=st; i<nums.size(); i++){
            if(i>st && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            FSS(i+1, nums, curr, result);
            curr.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<int>curr;
        vector<vector<int>>result;

        FSS(0, nums, curr, result);
        return result;
    }
};