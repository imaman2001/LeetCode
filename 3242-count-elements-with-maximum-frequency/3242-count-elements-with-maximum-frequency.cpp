class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int , int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxIndex = 0;
        for(int i=0; i<nums.size(); i++){
            maxIndex = max(maxIndex , mp[nums[i]]);
        }
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]] == maxIndex){
                count++;
            }
        }
        return count;
    }
};