class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // brute force 
        // int n = nums.size();
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i , j};
        //         }
        //     }
        // }
        // return {}; 

        unordered_map<int,int> map;  // sum , i
        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i];    // target - arr[i] and store in map with val : idx
            if(map.count(comp)){       // check the bachi hui value map k ander currValue se add krke target k equal ho rhi hai ya nhi
                return {map[comp], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};