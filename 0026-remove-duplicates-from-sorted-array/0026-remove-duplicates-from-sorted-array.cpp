class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int k=1;
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i] != nums[i-1]){
        //     nums[k] = nums[i];
        //     k++;
        //     }
        // }
        // return k;

        //////// TC: O(n) , SC: O(1)
        int i=0;
        for(int j=1; j<nums.size(); j++){
            if(nums[i] < nums[j]){
                int temp = nums[i+1];
                nums[i+1] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
        return i+1;
    }
};