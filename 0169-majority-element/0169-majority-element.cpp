class Solution {
public:
    int majorityElement(vector<int>& nums) {
    // Better Approach
        // unordered_map<int, int> m;
        // for(int i=0; i<nums.size(); i++){
        //     m[nums[i]]++;
        // }
        
        // for(pair<int, int> p : m){
        //     if(p.second > nums.size()/2){
        //         return p.first;
        //     }
        // }
        // return 0;

    // Optimal Approach
        int n = nums.size();
        int count1 = 0;
        int ele;

        for(int i=0; i<n; i++){
            if(count1 == 0){
                count1++;
                ele = nums[i];
            } else if(ele == nums[i]){
                count1++;
            } else {
                count1--;
            }
        }

        int count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                count2++;
            }
        }

        if(count2 > (n/2)) return ele;

        return -1;
    }
};