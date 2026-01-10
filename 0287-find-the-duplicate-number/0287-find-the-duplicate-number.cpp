class Solution {
private: 
    int check(vector<int>& nums , int value){
        int count = 0;
        for(int num : nums){
            if(num <= value){
                count++;
            }
        }
        return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
        // int i = 1; 
        // int j = nums.size() - 1;

        // while(i <= j){
        //     int mid = i + (j - i) / 2;
        //    if(check(nums , mid) > mid){
        //     j = mid - 1;
        //    }
        //    else {
        //     i = mid + 1;
        //    }
        // }
        // return i;

    // ......... BF ............ Approach.................
        // sort(nums.begin() , nums.end());
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] == nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return 0;

    // ....... Better Approach ...................
        vector<int>freq(nums.size() + 1 , 0);
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]] == 0){
                freq[nums[i]] += 1;
            } else {
                return nums[i];
            }
        }
        return 0;
    }
};