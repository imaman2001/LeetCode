class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        vector<int>st;
        sort(nums.begin(), nums.end());

        int curr = nums[0];
        for(int i=0; i<nums.size(); curr++, i++){
            if(curr < nums[i]){
                st.push_back(curr);
                i--;
            }
        }
        
        return st;
    }
};