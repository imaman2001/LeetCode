class Solution {
public:
    /// vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>>ans;
    //     sort(nums.begin() , nums.end());
        
    //     for(int i=0; i<n; i++){
    //         if(i>0 && nums[i] == nums[i-1]){
    //             continue;
    //         }
    //         int j=i+1; 
    //         int k=n-1;

    //         while(j<k){
    //             int sum = nums[i] + nums[j] + nums[k];
    //             if(sum<0){
    //                 j++;
    //             }
    //             else if(sum>0){
    //                 k--;
    //             }
    //             else{
    //                  vector<int>temp = {nums[i] , nums[j] , nums[k]};
    //                 ans.push_back(temp);
    //                 j++;
    //                 k--;
    //                 while(j<k && nums[j] == nums[j-1]){
    //                     j++;
    //                 }
    //                 while(j<k && nums[k] == nums[k+1]){
    //                     k--;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
    
    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            } 
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0){
                    left++;
                } else if(sum > 0){
                    right--;
                } else{
                    vector<int>temp = {nums[i] , nums[left] , nums[right]};
                    ans.push_back(temp);
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                    while(right > left && nums[right] == nums[right+1]){
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};