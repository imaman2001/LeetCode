class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(pair<int, int> p : m){
            if(p.second > nums.size()/2){
                return p.first;
            }
        }
        return 0;
    }
};