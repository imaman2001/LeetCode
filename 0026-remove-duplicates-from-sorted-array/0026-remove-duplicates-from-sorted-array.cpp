#include<unordered_set>
class Solution {
public:
        // TC: O(n) , SC: O(1)

    int removeDuplicates(vector<int>& nums) {  
        int idx = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[idx] < nums[i]){
                int temp = nums[idx+1];
                nums[idx+1] = nums[i];
                nums[i] = temp;
                idx++;
            }
        }
        return idx+1;
    }

    // int removeDuplicates(vector<int>& nums){
    //     unordered_set<int> seen;
    //     int idx = 0;
    //     for(int num : nums){
    //         if(seen.find() == seen.end()){
    //             seen.insert(num);
    //             nums[idx] = num;
    //             idx++;
    //         }
    //     }
    //     return idx;
    // }
};