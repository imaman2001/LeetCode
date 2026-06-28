class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int low = 0 , high = nums.size() - 1;
    //     while(low<=high){
    //         int mid = (low + high) / 2;

    //         if(nums[mid] == target){
    //             return mid;
    //         }

    //         if(nums[low] <= nums[mid]){
    //             if(nums[low] <= target && target < nums[mid]){
    //                 high = mid - 1;
    //             } else {
    //                 low = mid + 1;
    //             }
    //         } else {
    //             if(nums[mid] < target && target <= nums[high]){
    //                 low = mid + 1;
    //             } else {
    //                 high = mid - 1;
    //             }
    //         }
    //     }
    //     return -1;
    // }

    // int search(vector<int>& nums, int target){
    //     int low = 0;
    //     int high = nums.size()-1;
    //     while(low <= high){
    //         int mid = (low+high)/2;
    //         if(nums[mid] == target) return mid;

    //         // check if sorted
    //         if(nums[low] <= nums[mid]){
    //             if(nums[low] <= target && target < nums[mid]){
    //                 high = mid-1;
    //             } else{
    //                 low = mid+1;
    //             }
    //         } else {
    //             if(nums[high] >= target && target > nums[mid]){
    //                 low = mid+1;
    //             } else{
    //                 high = mid-1;
    //             }
    //         }
    //     }
    //     return -1;

    int search(vector<int>& nums, int target){
        int st = 0;
        int end = nums.size() -1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(nums[mid] == target) return mid;

            if(nums[st] <= nums[mid]) {
                if(nums[st] <= target && target < nums[mid]){
                    end = mid-1;
                }else{
                    st = mid + 1;
                }
            }else {
                if(nums[mid] < target && target <= nums[end]){
                    st = mid + 1;
                } else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};