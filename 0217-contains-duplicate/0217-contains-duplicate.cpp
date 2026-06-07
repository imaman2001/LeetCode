class Solution {
public:
    bool containsDuplicate(vector<int>& nums){
        // unordered_set<int> st;
        // for(int ele : nums){
        //     st.insert(ele);
        // }
        // // remove duplicate elements from set it stores unique only 
        // return st.size() < nums.size();

        unordered_set<int>st;

        for(int num : nums){
            st.insert(num);
        }
        if(st.size() < nums.size()){
            return true;
        }

        return false;
    }
};