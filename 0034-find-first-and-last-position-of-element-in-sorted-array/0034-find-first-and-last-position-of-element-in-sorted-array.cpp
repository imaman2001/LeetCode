class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        // take 2 size of res and initilize all 2 values as -1
        vector<int>res(2,-1);

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] > target)
                high = mid-1;
            
            else if(nums[mid]<target)
                low = mid + 1;

            else{
                if(mid == 0 || nums[mid-1]!=nums[mid]) { 
                  res[0]=mid;
                  break;
                } 
                else {
                    high=mid-1;
                }
            }
        }
        low=0; high=n-1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] > target)
                high = mid-1;

            else if(nums[mid]<target)
                low = mid + 1;
            
            else{
                if(mid == n-1 || nums[mid+1]!=nums[mid]) { 
                  res[1]=mid;
                  return res;
                } 
                else  
                  low=mid+1;
            }
        }
        return res;
    }
};