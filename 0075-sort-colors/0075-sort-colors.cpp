class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0, mid = 0, end = nums.size()-1;

        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums[st] , nums[mid]);
                st++, mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid] , nums[end]);
                end--;
            }
        }
    }
    


// ....................... Brute Force Approach .............................
    // void sortColors(vector<int>& nums) {
    //     int count0 = 0 , count1 = 0, count2 = 0;

    //     for(int i=0; i<nums.size(); i++){
    //         if(nums[i] == 0) count0++;
    //         else if(nums[i] == 1) count1++;
    //         else count2++;
    //     }

    //     int idx = 0;
    //     while(count0 != 0){
    //         nums[idx] = 0;
    //         idx++;
    //     }
    //     while(count1 != 0){
    //         nums[idx] = 1;
    //         idx++;
    //     }
    //     while(count2 != 0){
    //         nums[idx] = 2;
    //         idx++;
    //     }
    // }
};